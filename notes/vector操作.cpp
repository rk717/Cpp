用erase 来 给vector 去除重复

sort( vec.begin(), vec.end() );
vec.erase( unique( vec.begin(), vec.end() ), vec.end() );

///////////////////////////////////////////////////////////////////

找vector里的最大值
//finding the maximum element
    int max = *max_element(v1.begin(), v1.end());
