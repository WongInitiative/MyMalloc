# MyMalloc & MyFree

MyMalloc()

Overall Design for MyMalloc:
We start with representing the memory as 1 free block with a metadata tag at the beginning. The metadata structure provides information on a particular block of memory. This information includes the state of the block (i.e. whether it is in use or free) and size of the block itself (not including the size of the metadata). We give the user a ptr to the address right after the metadata of a particular block, so assuming we start at the beginning of a block this would be the start of metadata + sizeof(metadata). Since the metadata takes up a certain amount of space, we account for this when we check to see if there is a region of free space that can accomodate the user's memory. In order to be as space efficient as possible, we designed our metadata to be as small as was feasible in our implementation. This is discussed in 'Specifications'. Whenever the user mallocs some memory into a free block, we split the free block into two blocks, one used (to contain the user's data) and one free (to represent the rest of the free space that can be used by a future malloc call) each of these blocks have their own metadata tag. All of these blocks are contiguous so iterating through them would be a matter of pointer arithmetic. (beginning of block + sizeof(metadata) + blocksize) gets us to the start of the next block. In this way we iterate through the blocks stored in our byte array and use a first fit algorithm to find the the first block that is both free and has space large enough to contain the user's data. Once we find this block, we return a void pointer to the address right after the metadata of the block. 

Specifications For Metadata Structure:
To reduce the size of our meta struct, we used an unsigned int as a bitfield of 13 bits to contain the size of used space(Since we only need 13 bits to represent the maximum possible size of 4096 bytes), and an unsigned int bitfield of 1 to represent if the space is used or free. (All of this is stored in 2 bytes by the compiler). Thus we are able to minimize our data into 2 bytes. 


Overall Design for MyFree:
Since every block is contiguous we can iterate through each block and check the address right after the metadata. If this matches the address that the user specified in his/her call to myfree() and the block is in use, then we change the metadata so the block represents a free space and have that free space "point" to the next used space(by changing the blocksize to include itself + the size of all free blocks before the next used space + the size of each block's metadata). If it's the last block in the array it points to nothing (aka the blocksize is not chnaged). So in other words during our search for the next used space, if we cross other free blocks they get "absorbed" into the block that we just freed. If the block being freed is not the first block, we also check the the block right before it. If this block in use then we do nothing, but if it's free then we do the exact same process that I described except by starting with the previous block rather than the freed block. In this way the previous block will then point to the next used block, and it's size will include all the free space in between.

Memgrind:

Results:
	Workload 1: 11.6 ms
	Workload 2: 51.59 ms
	Workload 3: 251.80 ms
	Workload 4: 801.37 ms
	Workload E: 201.50 ms
	Workload F: 124.37 ms

Discussion:
	We ran each of the workloads independently of one another as well as simultaenously. We found the data to be consistent regardless of whether we ran independently or simultaneously. Its more important to note that this data reflectsthe times that appeared most often. Our unique workloads (E and F), which are discussed in detail in testplan.txt, indicate that our firstfit algorithm optimizes the usage of the space because alternate areas that are freed (what we do in workLoad F) can then be used for memory that is malloced. 

