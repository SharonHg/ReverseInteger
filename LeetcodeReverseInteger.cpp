class Solution {
public:

  
    int reverse(int x) {
        
        stack<int>r;
        stack<int>tens;
        if((x<0&&x>-9)||(x>=0&&x<=9))
        return x;

        for(int i = 9; i>=0; i--)
        {
            int a =x/(pow(10,i));
            
            r.push(a);
            x=x-(a*(pow(10,i)));
        }        

        bool headzero = true;

        while(r.empty()==false||headzero == true)
        {
            if(r.top()!=0)
            {
                headzero = false;
            }
            if(headzero==false)
            {
                tens.push(r.top());
            }
            r.pop();
        }
        headzero = true;

        while(headzero == true)
        {
            if(tens.top()!=0)
            {
                headzero = false;
            }
            else
            {
                tens.pop();
            }
        }

        for(int i = 0; i<=9;i++)
        {
            if(tens.empty()==true)
            {
                break;
            }
            else
            {
                long temp = x+(tens.top())*pow(10,i);
                x+=(temp-x);
                if(temp!=x)
                {
                    return 0;
                }
                tens.pop();  
            }
    
        }     
        return x;
    }
};