/*
컴퓨팅 사고 프로젝트 코드 파일
제작자 : 김민기
최종 수정일시 : 2020.5.25
*/
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>

long long int recursiveFivo(long long int n){
    if(n == 1 || n == 2){
        return 1;
    }
    else{
        return recursiveFivo(n - 2) + recursiveFivo(n - 1);
    }
}

long long int iterativeFivo(long long int n){
    if(n == 1 || n == 2){
        return 1;
    }
    else{
        long long int a = 1, b = 1, temp;
        for(int i = 2; i < n; i++){
            temp = a;
            a = b;
            b = a + temp;
        }
        return b;
    }
}

long long int dynamicIterativeFivo(long long int n){    //반복
    long long int array[1000000] = {0, 1, 1};

    if(n == 1 || n == 2){
        return array[n];
    }
    else{
        for(int i = 3; i <= n; i++){
            array[i] = array[i - 1] + array[i - 2];
        }
        return array[n];
    }
}

long long int arrayFivo(long long int n, long long int array[]){
    if(n == 1 || n == 2){
        return array[n];
    }
    
    if(array[n] != 0)
        return array[n];

    array[n] = arrayFivo(n - 1, array) + arrayFivo(n - 2, array);

    return array[n];
}

long long int dynamicRecursiveFivo(long long int n){    //동적
    long long int array[1000000] = {0, 1, 1};

    return arrayFivo(n, array);
}

void copyTwoDimensionArray(long long int des[][2], long long int src[][2]){ //2차원 배열을 복사할 함수
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            des[i][j] = src[i][j];
        }
    }
}

void multiplyMatrix(long long int argu1[][2], long long int argu2[][2], long long int output[][2]){   //2차원 배열을 곱하는 함수
    long long int temp1[2][2] = {0};
    long long int temp2[2][2] = {0};
    copyTwoDimensionArray(temp1, argu1);
    copyTwoDimensionArray(temp2, argu2);
    long long int temp = 0;                                                                           //output의 각 원소에 저장할 값을 잠시 보관할 변수

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                temp += temp1[i][k] * temp2[k][j];
            }
            output[i][j] = temp;
            temp = 0;
        }
    }
}

long long int matrixFivo(long long int n){                       //행렬의 곱셈으로 피보나치 수열을 구하는 함수
    long long int output[2][2] = {{1, 0}, {0, 1}};
    long long int tempMatrix[2][2] = {{1, 1}, {1, 0}};
    int k = 0;

    while (pow(2, k) <= n){
        if((n & (1 << k++)) != 0){
            multiplyMatrix(output, tempMatrix, output);
        }
        multiplyMatrix(tempMatrix, tempMatrix, tempMatrix);
    }

    return output[1][0];
}

long long int mathmaticalExpression(long long int n){
    double root5 = pow(5, 0.5);

    return 1 / root5 * (pow((1 + root5) / 2, n) - pow((1 - root5) / 2, n) );
}

int main(){
    long long int input, fivo;
    clock_t start, end;
    scanf("%lld", &input);

    double total = 0;

    for(int i = 0; i < 100; i++){
        start = clock();
        fivo = recursiveFivo(input);
        end = clock();
        total += (double)(end - start)/CLOCKS_PER_SEC;
    }

    printf("time : %f, result : %lld\n", total / 100.0, fivo);
    total = 0;



    for(int i = 0; i < 100; i++){
        start = clock();
        fivo = dynamicIterativeFivo(input);
        end = clock();
        total += (double)(end - start)/CLOCKS_PER_SEC;
    }

    printf("time : %f, result : %lld\n", total / 100.0, fivo);
    total = 0;
    

    for(int i = 0; i < 100; i++){
        start = clock();
        fivo = dynamicRecursiveFivo(input);
        end = clock();
        total += (double)(end - start)/CLOCKS_PER_SEC;
    }

    printf("time : %f, result : %lld\n", total / 100.0, fivo);
    total = 0;

    for(int i = 0; i < 100; i++){
        start = clock();
        fivo = iterativeFivo(input);
        end = clock();
        total += (double)(end - start)/CLOCKS_PER_SEC;
    }

    printf("time : %f, result : %lld\n", total / 100.0, fivo);
    total = 0;
    

    for(int i = 0; i < 100; i++){
        start = clock();
        fivo = matrixFivo(input);
        end = clock();
        total += (double)(end - start)/CLOCKS_PER_SEC;
    }

    printf("time : %f, result : %lld\n", total / 100.0, fivo);
    total = 0;

    for(int i = 0; i < 100; i++){
        start = clock();
        fivo = mathmaticalExpression(input);
        end = clock();
        total += (double)(end - start)/CLOCKS_PER_SEC;
    }

    printf("time : %f, result : %lld\n", total / 100.0, fivo);
    total = 0;



    return 0;
}
