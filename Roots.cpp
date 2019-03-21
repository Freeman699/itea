#include <cstdio>
#include <cmath>
#include <iostream>

using std::endl;
using std::cout;
using std::cin;

void RootSearch(float coefficient1, float coefficient2, float freeTerm);
void OneRootSearch(float coefficient2, float freeTerm);
void RootSearchComplex(float coefficient1,float coefficient2,float freeTerm);

int main(void)
{
    setlocale(LC_ALL, "Russian");
    
    float coefficient1,coefficient2,freeTerm;

    printf("\n///////////////////////////////////////////////////////////////////");
    printf("\n/ Программа для вычисления корней квадратного уравнения /");
    printf("\n///////////////////////////////////////////////////////////////////");
    printf("\nКвадратное уравнение имеет вид: ax^2 + bx + c = 0\n");


DataInputMark:
    printf("\nВведите коэффициент a:");  
    cin >> coefficient1;
    printf("\nВведите коэффициент b:");
    cin >> coefficient2;
    printf("\nВведите свободный член c:");
    cin >> freeTerm;  

    cout << endl << endl << "Уравнение имеет вид: " << coefficient1 << "x^2 + " << coefficient2 << "x + " << freeTerm << " = 0" <<  endl;

    short answer = 0;
    do
    {
        printf("\nДанные введены верно? \n 1 - Да  \n 2 - Нет \n 3 - Выход \n\n");
        cin >> answer;

        switch (answer)
        {
            case 1:
                break;

            case 2:
                goto DataInputMark; // line 21
                break;
            
            case 3:
                return 0;
                break;

            default:
                printf("\n\nНеверная опция...\n");
                break;
        }
    }while(answer != 1);

    



    if(coefficient1 == 0) OneRootSearch(coefficient2, freeTerm);

    else if(pow(coefficient2,2) < (4*coefficient1*freeTerm))
    {
        short complexFlag = 0;
        printf("Уравнение не имеет вещественных корней\n Хотите продолжить?\n 1 - Да \n");
        cin >> complexFlag;
        if(complexFlag == 1)
        {
            RootSearchComplex(coefficient1,coefficient2,freeTerm);
        }
    }

    else RootSearch(coefficient1,coefficient2,freeTerm);

    return 0;
}



void RootSearch(float coefficient1, float coefficient2, float freeTerm)
{ 
    double realDiscriminant = sqrt(pow(coefficient2,2) - 4*coefficient1*freeTerm);
    cout << endl << "Первый корень: " << ((-coefficient2 + realDiscriminant) / (2*coefficient1)) << endl
         <<         "Второй корень: " << ((-coefficient2 - realDiscriminant) / (2*coefficient1)) << endl;

    return;
}



void OneRootSearch(float coefficient2, float freeTerm)
{
    if(coefficient2 == 0)
    {
        printf("Корнями данного уравнения являются любые 2 комплексных числа");
    }
    else cout << endl << "Корень данного уравнения: " << (-freeTerm  / coefficient2) << endl;

    return;
}



void RootSearchComplex(float coefficient1,float coefficient2,float freeTerm)
{
    double realRootPart = (-coefficient2)/(2*coefficient1);
    double complexDiscriminant = sqrt( (-1) * (pow(coefficient2,2) - 4*coefficient1*freeTerm) );

    cout << endl << "Первый корень: " << realRootPart << " + " << (complexDiscriminant/(2*coefficient1)) << "i" << endl
         <<         "Второй корень: " << realRootPart << " - " << (complexDiscriminant/(2*coefficient1))  << "i" << endl;

    return;
}


