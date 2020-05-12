用erase 来 给vector 去除重复

sort( vec.begin(), vec.end() );
vec.erase( unique( vec.begin(), vec.end() ), vec.end() );

或者 https://www.techiedelight.com/check-vector-contains-given-element-cpp/
再创建一个 临时vector， 然后原来的vector 放element 进去， 如果 临时vector有了， 就不放
vector <string> b_name;
    for(int i = 0; i < name.size(); i++)
    {
        b_name.push_back(name[i]);
    }

    vector <string> b_setName;
    for(int i = 0; i < b_name.size(); i++)
    {
        if(find(b_setName.begin(), b_setName.end(), b_name[i])!= b_setName.end()) 
        {
            continue;
        }
        else
        {
            b_setName.push_back(b_name[i]);
        }
        
    }
///////////////////////////////////////////////////////////////////

找vector里的最大值
//finding the maximum element
    int max = *max_element(v1.begin(), v1.end());
