#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
int balance = 5000;
int mlp = 1;
int bid = 100;
int ch, i, num = 1;
int arr[3];

while(1){
printf("///Гра Однорукий пірат///\nЩоб почати гру натисніть 1\nЩоб побачити виграшні комбінації натисніть 2\nЩоб завершити гру натисніть 3\n");
scanf("%d", &ch);
if(ch == 1){
while(num != -1){
balance -= bid;
printf("\nВаш баланс становить %d, ваша ставка становить %d\n", balance, bid);
for(i = 0; i < 3; i++){
arr[i] = rand()%8;
printf("%d ", arr[i]);
}
if(arr[0] == 5 || arr[0] == 7){
mlp = 15;
if(arr[1] == arr[0]){
mlp = 30;
if(arr[2] == arr[1]){
if(arr[0] == 5){
mlp = 50;
num = 5;
}else{
printf("JACKPOT!!!\nВи виграли JACKPOT, вітаємо!!!");
return 0;
}}}
num = 5;
}else{
if(arr[0] == arr[1] && arr[1] == arr[2]){
mlp = 21;
num = 5;
}else{
num = 0;
}}
if(num == 0)
printf("\nСпробуйте ще раз!( Цього разу вам пощастить!");
if(num == 5){
printf("\nВітаю!!! Ви виграли %d ігрових кредитів до балансу!!!", bid*mlp);
balance += bid*mlp;
mlp = 1;
}
sleep(1);
if(balance <= 0)
num = -1;
}
printf("\nНа жаль ви програли!");
return 0;
}else if(ch == 2){
printf("\n Виграшні комбінації\n Бонус 21: 000 111 222 333 444\n Бонус 15: 5XX 7XX\n Бонус 30: 55X 77X\n Бонус 50: 555\nJACKPOT!!! : 777\n\n");
}else return 0;
}
return 0;
}
