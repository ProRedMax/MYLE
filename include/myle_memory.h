#pragma once

#include <vector>
#include <unordered_map>

#include <assert.h>

//Warning: This feature is not yet completed, it could be that unexpected behavior occurs. Use at your own risk.

namespace MYLE
{
    /**
     * \brief Faster memory access
     */
    class ResourceManager
    {
        //Represents a segment of free space in the memory block.
        struct Segment
        {
            uint32_t m_Begin = 0;
            uint32_t m_End = 0;
        };

        //Represents a memory block with a vector of segments, which can be populated with data.
        struct Block
        {
            Block(void* block, uint32_t blockSize)
                : m_Block(block), m_BlockSize(blockSize)
            {
                //Init the whole block as a free segment.
                m_Segments.push_back({0, m_BlockSize});
            }

            void* m_Block = nullptr;
            uint32_t m_BlockSize = 0;

            std::vector<Segment> m_Segments;
        };

    public:

        ~ResourceManager()
        {
            for (auto it = m_Blocks.begin(); it != m_Blocks.end(); it++)
            {
                std::free(it->second.m_Block);
            }

            m_Blocks.clear();
        }

        /**
        * \brief Allocates a resource T with the given parameters.
        * \param Parameters to initialize the resource.
        * \return A weak_ptr to the resource.
        * 
        * TODO
        */
        //template<typename T, typename... TArgs>
        //inline std::weak_ptr<T> AllocateResource(TArgs... Args)
        //{
        //}


        /**
        * \brief Initialize a resource with the given parameters in an memory block. 
        * Warning: Extensive use can lead to memory fragmentation. It is heavily advised to store just one type in one block.
        * \param The id of the block in which the resource should be stored.
        * \param The parameters to initialize the resource.
        */
        template <typename T, typename... TArgs>
        T* alloc_resource(uint32_t blockID, TArgs ... Args)
        {
            Block& block = m_Blocks.at(blockID);

            T* returnValue = nullptr;

            uint32_t index = -1;

            for (size_t i = 0; i < block.m_Segments.size(); i++)
            {
                Segment& segment = block.m_Segments.at(i);

                //If T fits in the given segment store it there.
                if (sizeof(T) <= segment.m_End - segment.m_Begin)
                {
                    returnValue = &((*(T*)(static_cast<char*>(block.m_Block) + segment.m_Begin)) = T{Args...});

                    //Store the index in which the value was stored.
                    index = i;
                }
            }

            if (index == -1)
            {
                //If this occurs than there is no segment in any given block in which T would fit.
                //This does not necessarily mean that the computer is out of memory.
                assert(false, "Out of memory.");
                return nullptr;
            }
            Segment& segment = block.m_Segments.at(index);

            //If T fills up the whole segment delete it from the list.
            if (sizeof(T) == segment.m_End - segment.m_Begin)
            {
                block.m_Segments.erase(block.m_Segments.begin() + index);
                return returnValue;
            }

            uint32_t end = 0;

            //We are now calculating the remaining space of the segment after T was placed.
            //If there is another segment after the current one, then the new one ends at the beginning of the next segment, otherwise it ends at the end of the block.
            end = block.m_Segments.size() - 1 < index + 1 ? block.m_BlockSize : block.m_Segments.at(index + 1).m_Begin;

            //Now push the new segment on the unordered_map
            block.m_Segments.push_back({segment.m_Begin + sizeof(T), end});

            //And erase the old one
            block.m_Segments.erase(block.m_Segments.begin() + index);

            //Return a pointer to the value
            return returnValue;
        }


        /**
        *  \brief Frees a resource if it was stored in an allocated memory block.
        *  \param resource The pointer to the given resource.
        */
        template <typename T>
        void free_resource(T* resource)
        {
            for (auto& it : m_Blocks)
            {
                //Calculate the offset from the starting of the memory block to the resource.
                ptrdiff_t byteDiff = (char*)resource - (char*)it.second.m_Block;

                //If the offset is negative, then the resource is somewhere before the memory block.
                //If the offset is positive and not greater than the block size, then the resource is in the block and thus can be freed.
                if (byteDiff >= 0 && byteDiff < it.second.m_BlockSize)
                {
                    it.second.m_Segments.push_back({(uint32_t)byteDiff, (uint32_t)byteDiff + sizeof(T)});
                    return;
                }
            }

            assert(false, "The given resource is not located in any given memory block");
        }


        /**
        * \brief Allocates a new block of memory with the given size.
        * \param id The id of the memory block.
        * \param size The size of the memory block.
        */
        void alloc_memory_block(uint32_t id, uint32_t size)
        {
            void* block = std::malloc(size);

            m_Blocks.insert({id, {block, size}});
        }

        /**
        * \brief Frees The block of memory at the given index.
        * \param index The index of the block.
        */
        void free_memory_block(uint32_t index)
        {
            std::free(m_Blocks.at(index).m_Block);

            m_Blocks.erase(index);
        }

    private:
        std::unordered_map<uint32_t, Block> m_Blocks;
    };
}
