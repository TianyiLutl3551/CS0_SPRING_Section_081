#include<math.h>
#include<stdio.h>
int fun(int x, int y, int z){
    float a = acos((z*z + y*y - x*x) /(2.0*y*z));
    float b = acos((x*x + z*z - y*y) /(2.0*x*z));
    float c = acos((x*x + y*y - z*z) /(2.0*x*y));
    float threshold = 0.0001;
    if(a>=b-threshold && a<=b+threshold
    && a>=c-threshold && a<=c+threshold){
        return 1;
    }
    else if((a>=b-threshold && a<=b+threshold)
    || (a>=c-threshold && a<=c+threshold)){
        return 2;
    }
    else{
        return 3;
    }
}

int main(){
    int x, y, z;
    int type;
    scanf("%d%d%d",&x,&y,&z);
    type = fun(x, y, z);
    switch(type){        
        case 1: printf("This is an equilateral triangle.\n");break;
        case 2: printf("This is an isosceles triangle.\n");break;
        case 3: printf("This is a normal triangle.\n");break;

    }
    return 0;
}
