class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int counter=0;
        int x=0;

        for(int i=0;i<32;i++){
            if( (num2 >> i) & 1  ){
                counter++;
            }
        }

        for(int i =31 ; i>=0 ;i--){
            if( ( ( num1 >> i ) & 1) && counter ){
                x|=(1<<i);
                counter--;             
            }
        }

        int i=0;
        
        while(counter > 0){
            if( ((x >> i) & 1) ){
                i++;
                continue;
            }
            x|=(1<<i);
            i++;
            counter--; 
        }

        return x;
    }
};