#include<stdio.h>
#include<math.h>
#include<time.h>

int okinawa=0;int fukuoka=1;int hiroshima=2;int osaka=3;int kyoto=4;
int nagoya=5;int yokohama=6;int tokyo=7;int utsunomiya=8;int sapporo=9;
int wakayama=10; int kanazawa=11; int karuizawa=12; int sendai=13; int aomori=14;



int kaisu=1;

 double min_dis=100000;//��΂ɍŏ��ɂȂ�Ȃ����l����U����Ă���
 int temp[20];
 int tempcopy[20][20]; 


/*********2�̒n�_�̋������v�Z���ĕԂ��֐�************/
double di_dis(int a,int b){
  double dis;
  int city_x[30];
  int city_y[30];
  city_x[okinawa]=0;city_y[okinawa]=0;//okinawa
  city_x[fukuoka]=2;city_y[fukuoka]=3;//fukuoka
  city_x[hiroshima] =4;city_y[hiroshima]=4;//hiroshima
  city_x[osaka]=10;city_y[osaka]=5;//osaka
  city_x[kyoto] =11;city_y[kyoto]=6;//kyoto
  city_x[nagoya]=13;city_y[nagoya]=7;//nagoya
  city_x[yokohama]=17;city_y[yokohama]=7;//yokohama
  city_x[tokyo] =18;city_y[tokyo]=9;//tokyo
  city_x[utsunomiya]=19;city_y[utsunomiya]=12;//utsunomiya
  city_x[sapporo]=20;city_y[sapporo]=29;
  city_x[wakayama]=10;city_y[wakayama]=4;//wakayama
  city_x[kanazawa]=13;city_y[kanazawa]=13;//kanazawa
  city_x[karuizawa]=16;city_y[karuizawa]=12;//karuizawa
  city_x[sendai]=20;city_y[sendai]=15;//sendai
  city_x[aomori]=20;city_y[aomori]=22;//sapporo


  dis=sqrt((city_x[a]-city_x[b])*(city_x[a]-city_x[b])+(city_y[a]-city_y[b])*(city_y[a]-city_y[b]));
  return dis;
}

/**********�i1�̃p�^�[���ɂ�����j�S�Ă̒n�_���Ȃ���������Ԃ��֐�**********/
double all_dis(int *num,int numlen){
  double all_dis_return=0;
for(int i=0;i<numlen-1;i++){
  all_dis_return=all_dis_return+di_dis(num[i],num[i+1]);
}
all_dis_return=all_dis_return+di_dis(num[0],num[numlen-1]);//�ŏ��ƍŌ�𑫂��B
//double all_dis_return=di_dis(city1,city2)+di_dis(city2,city3)+di_dis(city3,city4)+di_dis(city4,city5)+di_dis(city5,city1);

return all_dis_return;
}

 int num=0;
/******************�ċA�֐�*********************/
void loop(int *city,int numlen1,int numlen2)//���̕�����z��ɕς����� //numlen2��ς�����ɂ���B
{
    int e;
    int a=numlen1;
    if(num==0){//�ŏ����������Ƃ��Čv�Z����
    for(int i=0;i<numlen1;i++){
    temp[i]=city[i];
    }
    num++;
    }

  for(int i=0;i<numlen2;i++){
  tempcopy[a-i-1][numlen2-1]=temp[a-i-1];
 // printf("%d",tempcopy[i][titen-1]);
  }
 
//printf("\n");
  for(int k=0;k<numlen2;k++){
    if(numlen2==2){
          double ex_dis=all_dis(temp,sizeof(temp)/sizeof(int));//temp�̃A�h���X��temp�̒�����^����

        //  printf("%d�p�^�[����:%lf\n",kaisu,ex_dis);////�K�v

          kaisu++;
         // printf("%d%d%d%d%d%d%d\n",temp[a-7],temp[a-6],temp[a-5],temp[a-4],temp[a-3],temp[a-2],temp[a-1]);
          if(ex_dis<min_dis){//�������̎��_�̍ŏ��l��菬�����̂��o���炻�̒l��min_dis�ɑ��
          min_dis=ex_dis;
          //printf("�ŏ��l���X�V����܂���\n");
          }
  }
  else{
   // printf("%p,%d,%d\n",city,numlen1,numlen2);
     loop(city,numlen1,numlen2-1);
     }

//���[�v�Ō�̎�
  if(k==numlen2-1)
  {
    for(int i=0;i<numlen2;i++){
      temp[a-i-1]=tempcopy[a-i-1][numlen2-1];//����s�̐����Ŕ�ׂ���  
    }
    continue;
  }
  e=temp[a-numlen2];
  temp[a-numlen2]=temp[a-numlen2+1+k];
  temp[a-numlen2+1+k]=e;
  }
}

/*******************main�֐��i�ǂ̓s�s��ʂ邩�I���j***********************/
int main(void){
   //printf("�ŏ������F%lf\n",set(okinawa,fukuoka,hiroshima,osaka));
   //,utsunomiya,sapporo,wakayama,kanazawa
   int city[]={okinawa,fukuoka,hiroshima,osaka,kyoto,nagoya};
   int numlen=sizeof(city)/sizeof(int);

  clock_t start_clock, end_clock;
  start_clock = clock();
   loop(city,numlen,numlen);//�z��̃A�h���X�Ƃ��̒���
   printf("�ŏ��l�F%lf",min_dis);
   end_clock = clock();
    printf( "clock:%f\n",(double)(end_clock - start_clock) / CLOCKS_PER_SEC);
  return 0;
}