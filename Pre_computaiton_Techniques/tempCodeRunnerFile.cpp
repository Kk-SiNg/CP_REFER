 = max(mx_len, i+1);
        else{
            if(mp.find(sm - k) != mp.end()) mx_len = max(mx_len, i-mp[sm-k]);
        }