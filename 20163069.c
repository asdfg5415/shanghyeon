#include <stdio.h>

int main(void)
{
	int frame = 1; //frame 수를 의미
	int firstBowl,secondBowl,thirdBowl; //초구, 2구, 3구 의미
	int thirdAdmit = 0; // 3구 인정하시져? 10frame에서 스트라이크 혹은 스페어가 한번이라도 있으면 3구를 치게됨.
	int beforeBonus = 0;
	int beforeBeforeBonus = 0; //전 프레임이 스트라이크 혹은 스페어 였음을 의미 전전 프레임인지 확인해야함.
	int score = 0;
	while(frame <= 10){
		printf("%d번째 프레임 첫 번째 처리 핀수 : ",frame);
		scanf("%d",&firstBowl);
		if(firstBowl > 10 || 0 > firstBowl){
			printf("Error 핀 수는 0~10 사이의 정수여야합니다");
			break;
		}
		score += firstBowl;

		if(beforeBonus > 0){
			score += firstBowl;
			beforeBonus --;
		}// 저번 프레임에 스트라이크 또는 스페어가 있었으면 초구를 합해준다.
		if(beforeBeforeBonus > 0){
			score += firstBowl;
			beforeBeforeBonus --;
		}// 저번 프레임에 스트라이크 또는 스페어가 있었으면 초구를 합해준다.

		printf("****  현재까지 점수 : %d\n",score);

		if(frame != 10 && firstBowl == 10){ //frame¿ 10이면 그냥 더해주는거다.
			beforeBeforeBonus = beforeBonus; //이게 나올 경우는 연속 스트라이크 밖에 없음.
			beforeBonus = 2;
			frame++;
			continue;	
		}
		if(frame ==10 && firstBowl ==10){
			thirdAdmit = 1;
		}
		printf("%d번째 프레임 두번째 처리 핀 수 : ",frame);
		scanf("%d",&secondBowl);
		if(secondBowl > 10 || 0 > secondBowl){
			printf("Error 핀 수는 0~10 사이의 정수여야합니다.");
			break;
		}
		if( (firstBowl + secondBowl) > 10 && frame != 10){
			printf("Error 초구랑 두번째 구에서 친 핀 수가 10개가 넘으면 안됩니다.");
			break;
		}
		score += secondBowl;
		if(beforeBonus > 0){
			score += secondBowl;
			beforeBonus--;
		}// 저번 프레임에 스트라이크 또는 스페어가 있었으면 두번째구를 합해준다.
		if(beforeBeforeBonus > 0){
			score += secondBowl;
			beforeBeforeBonus --;
		}// 저번 프레임에 스트라이크 또는 스페어가 있었으면 초구를 합해준다.

		printf("****  현재까지 점수 : %d\n",score);

		if(frame!= 10 && firstBowl + secondBowl == 10 ){
			beforeBonus += 1;
		}
		if(frame == 10 && (firstBowl + secondBowl) ==10){
			thirdAdmit = 1;
		}
		if( thirdAdmit){
			printf("%d번째 프레임 세 번째 처리 핀 수 :  ",frame);
			scanf("%d",&thirdBowl);
			if(thirdBowl > 10 || 0 > thirdBowl){
				printf("Error 핀 수는 0~10 사이의 정수여야합니다.");
				break;
			}
			score += thirdBowl;
			printf("****  최종  점수 : %d\n",score);
		}
		frame++;
	}
	printf("끝!");
	return 0;
}
