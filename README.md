Hash table algorithm that maps different names to different 'buckets' on the hash table. Given someones name and its corresponding key (favourite drink) it hashes the name and stores it in one of the 'buckets'. Note: 'buckets' here are defined as an array of linked lists, with each node containing the name, drink, and pointer to the next node item. The  index (i.e which bucket) in which we place the name and key is determined by the output of the hash function. 