#include <stdio.h>

#include "stack_arr.h"
#include "stack_list.h"


enum { MOVE, BACK, FRONT, CURRENT, EXIT=9 };

void print_menu();

StackNode *sl_top = NULL; // 뒤로가기 스택 초기화
int sa_top = -1; // 앞으로가기 스택 초기화

int main(void)
{
    int number;
    char site[100][100];
    int site_num = 0;
    
    print_menu();
    while (1)
    {
        printf("\n>> ");
        scanf("%d",&number);

        switch(number)
        {
            case MOVE:
                printf("이동할 사이트 입력: ");
                scanf("%s", site[site_num]);
                sl_push(site[site_num]);
                printf("현위치: %s\n", sl_peek());
                site_num++;
                break;
                
            case BACK:
                sa_push(sl_peek());
                sl_pop();
                printf("뒤로 이동완료!\n현위치: %s\n", sl_peek());
                break;

            case FRONT:
                sl_push(sa_peek());
                sa_pop();
                printf("앞으로 이동완료!\n현위치: %s\n", sl_peek());
                break;

            case CURRENT:
                printf("뒤로가기 스택의 top값을 현위치로 간주하는 중... 현위치: %s\n", sl_peek());
                sl_printStack();
                sa_printStack();
                break;

            case EXIT:
                return 0;

            default:
                printf("잘못된 숫자를 입력하셨습니다.");
                break;
        }
    }

    return 0;
}

void print_menu()
{
    char *menu[] = {
        "\n",
        "-----Menu------",
        "0. 이동할 사이트 입력",
        "1. 뒤로가기(<-)",
        "2. 앞으로(->)",
        "3. 방문기록 확인",
        "9. 종    료"
    };

    for (int i = 0; i < 7; i++) { printf("%s\n", *(menu+i)); }
}
