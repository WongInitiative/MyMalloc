# MyMalloc & MyFree

MyMalloc()

Overall Design:
We have a metadata that provides information on a particular section of data. This information includes type of data (i.e. whether it is in use or free) and size of data.  We give the user a ptr to the first byte of the malloced array, aka the start of metadata + sizeof(metadata). Since the metadata takes up a certain size, we account for this when we check to see if there is a region of free space that can accomodate the user's memory. In order to be as space efficient as possible, we designed our metadata to be as small as was feasible in our implementation. This is discussed in 'Specifications'. Whenever the user malloced some memory into a free space, we split the free space with meta struct for the used data as well as the meta struct for the remaining free space. The meta struct for free space immediately follows the meta struct for used space. Also after the split, the meta struct for used space would "point" to the meta struct for free space. I use quotations because we do not use traditional pointers and rather use memory arithmetic to symbolically stitch metas together. Basically to access the next meta we increment to pointer to start of meta with  size of meta + the size of used space to get the next meta. 

Specifications:
To Reduce the size of our meta struct, we used a short to contain the size of used space and a bit field to represent if the space is used or free. Since we only need 13 bits to capture all size, we casted the short as a 13 bit string (although its stored as 2 bytes). The compiler tags the bitfield into the same bytes as the short though because the short only uses 13 bits, however we can access the bit field as if it were a variable. Thus we are able to minimize our data into 2 bytes. 

MyFree

Overall Design:
Since we have each metadata struct point to the next metadata (symbolically as discussed in mymalloc), we can iterate through to find the corresponding metadata for the space we want to free. Once we found this metadata, we can then change it to become a free space and have that free space point to the next used space (or if its the last meta in the array it points to nothing). As we find the next used space, if we cross other free spaces, we add the  memory size (i.e. the last 13 bits of the variable discussed in the specifications tab of myMalloc) to the meta data we converted to a free space. A special condition occurs if a used space is preceded by a free space. In this case, we can have the preceding metadata (which is free) point to the next used space, which must follow the meta data corresponding to the space we want to free. Since we are working with symbolic pointers, the meta data that now has no "pointer" to it (i.e. the meta data corresponding to the space we want to free) essentially become garbage value in the user's perspective. As they do not have access to our structure.


Specifications:
We use bitwise operations to convert the leftmost bit to a free. The operation is ultimately an & operation between 01111111111111 w/ our 14 bit variable that stores the type and size. We add the additional memory as we normally would since 13 bits is more than space for our memory.


Memgrind:

Unique Workloads:

Results:

Notes:

