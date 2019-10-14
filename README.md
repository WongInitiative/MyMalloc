# MyMalloc & MyFree

MyMalloc()

Overall Design:
We have a metadata that provides information on a particular section of data. This information includes type of data (i.e. whether it is in use or free), size of data, and location of next section of data. We give the user a ptr to the first byte of the malloced array, aka the start of metadata + sizeof(metadata). Since the metadata takes up a certain size, we account for this when we check to see if there is a region of free space that can accomodate the user's memory. In order to be as space efficient as possible, we designed our metadata to be as small as was feasible in our implementation. This is discussed in 'Specifications'. Whenever the user malloced some memory into a free space, we split the free space with meta struct for the used data as well as the meta struct for the remaining free space. The meta struct for free space immediately follows the meta struct for used space. Also after the split, the meta struct for used space would point to the meta struct for free space.   

Specifications:
To Reduce the size of our meta struct, we assigned an unsigned int to be a 14 bit address. The leftmost bit would represent the state of the corresponding space (i.e. is it free or used) whereas the other 13 bits would represent the size of the corresponding space. We also padded our array so that no matter the other of our data int the struct, it'd be rearranged to take up the least amount of memory.

MyFree

Overall Design:
Since we have each metadata struct point to the next metadata, we can iterate through to find the corresponding metadata for the space we want to free. Once we found this metadata, we can then change it to become a free space and have that free space point to the next used space or NULL (if we reach the end of the array). As we find the next used space if we cross other free spaces, we add the  memory size (i.e. the last 13 bits of the variable discussed in the specifications tab of myMalloc) to the meta data we converted to a free space. A special condition occurs if a used space is preceded by a free space. In this case, we can have the preceding metadata (which is free) point to the next used space, which must follow the meta data corresponding to the space we want to free. Since we are working with pointers, the meta data that now has no pointer to it (i.e. the meta data corresponding to the space we want to free) essentially become garbage value in the user's perspective. As they do not have access to our structure.


Specifications:
We use bitwise operations to convert the leftmost bit to a free. The operation is ultimately an & operation between 01111111111111 w/ our 14 bit variable that stores the type and size. We add the additional memory as we normally would since 13 bits is more than space for our memory.


Memgrind:

Unique Workloads:

Results:

Notes:

