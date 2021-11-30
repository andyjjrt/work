#include <stdio.h>
#include <string.h>
#include <stdlib.h>
long long int Max(long long int a,long long int b){
 return a > b ? a : b;
}
long long int Min(long long int a,long long int b){
 return a < b ? a : b;
}
long long int Cross(long long int X1,long long int Y1,long long int X2,long long int Y2){
 return (X2-X1)*(Y2-Y1);
}
int main(){
 char c;
 long long int xa1,xa2,xb1,xb2,xc1,xc2,ya1,ya2,yb1,yb2,yc1,yc2;
 scanf("(%lld,%lld,%lld,%lld)\n",&xa1,&ya1,&xa2,&ya2);
 scanf("(%lld,%lld,%lld,%lld)\n",&xb1,&yb1,&xb2,&yb2);
 scanf("(%lld,%lld,%lld,%lld)",&xc1,&yc1,&xc2,&yc2);
//================input========================================
 long long int ans=0;
 ans+=Cross(xa1,ya1,xa2,ya2);
 ans+=Cross(xb1,yb1,xb2,yb2);
 ans+=Cross(xc1,yc1,xc2,yc2);
//Ans = A + B + C
 long long int xab1=Max(xa1,xb1),yab1=Max(ya1,yb1),xab2=Min(xa2,xb2),yab2=Min(ya2,yb2);
 long long int Area_ab=0,iscross_ab=0;
 if(xab2 > xab1 && yab2 > yab1){
  iscross_ab=1;
  Area_ab=Cross(xab1,yab1,xab2,yab2);
 }
 
 long long int xac1=Max(xa1,xc1),yac1=Max(ya1,yc1),xac2=Min(xa2,xc2),yac2=Min(ya2,yc2);
 long long int Area_ac=0,iscross_ac=0;
 if(xac2 > xac1 && yac2 > yac1){
  iscross_ac=1;
  Area_ac=Cross(xac1,yac1,xac2,yac2);
 }

 long long int xbc1=Max(xb1,xc1),ybc1=Max(yb1,yc1),xbc2=Min(xb2,xc2),ybc2=Min(yb2,yc2);
 long long int Area_bc=0,iscross_bc=0;
 if(xbc2 > xbc1 && ybc2 > ybc1){
  iscross_bc=1;
  Area_bc=Cross(xbc1,ybc1,xbc2,ybc2);
 }

 long long int xabc1=Max(xab1,xc1),yabc1=Max(yab1,yc1),xabc2=Min(xab2,xc2),yabc2=Min(yab2,yc2);
 long long int Area_abc=0,iscross_abc=0;
 if(iscross_ab*iscross_ac*iscross_bc == 1){
  iscross_abc=1;
  Area_abc=Cross(xabc1,yabc1,xabc2,yabc2);
 }
 ans-=(Area_ab+Area_ac+Area_bc-Area_abc);
 printf("%lld\n",ans);
 //printf("%lld %lld %lld %lld\n",xa1,ya1,xa2,ya2);


 return 0;
}