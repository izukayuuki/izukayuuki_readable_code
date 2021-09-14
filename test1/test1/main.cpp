//
//  main.cpp
//  test1
//
//  Created by 井塚雄喜 on 2021/09/13.
//

//
//  main.cpp
//  test3
//
//  Created by 井塚雄喜 on 2021/09/13.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/*ファイル読み込み関数のfopen()でエラーが起こりNULLが返されてしまう*/

//ファイル読み込み関数
void ReadFile(const char *filename,char *word, int &num){
    FILE *fp;
    fp = fopen(filename, "r");
    //ファイルオープン失敗の時の処理
    if(fp==NULL){
        printf("ファイルオープン失敗¥n");
    }
    
    while(!EOF){
        fgets(word,100,fp);
        num++;
    }

    fclose(fp);
}

//ファイル書き込み関数
void MakeFile(const char *filename,char *word,int &num){
    FILE *fp;
    fp = fopen(filename,"w");
    if(fp==NULL){
        printf("ファイルオープン失敗¥n");
    }
    for(int i = 0;i<num;i++){
        fputc(word[num], fp);
    }
    fclose(fp);
}

int main(int argc, const char * argv[]) {
    int n = 0; //文字数
    char *word = new char[100];
    ReadFile("word.txt", word, n);
    MakeFile("Output.txt", word, n);
    return 0;
}



