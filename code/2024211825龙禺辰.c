#include<string.h>
#include<stdio.h>
struct string
{
    char chr[30];
    int len;
}sta[10010],emp;
int len,top;
char now[10010];
void nwadd()
{
    top=0;
    for(int i=0;i<len;++i)
    {
        if(now[i]=='/')
        {
            ++top;
            sta[top]=emp;
        }
        else    sta[top].chr[sta[top].len++]=now[i];
    }
}
void init()
{
    getcwd(now,10010);
    len=strlen(now);
    nwadd();
}
void outputnow()
{
    for(int i=1;i<=top;++i)
    {
        sta[top].chr[sta[top].len]='\0';
        printf("/%s",sta[i].chr);
    }
    printf("\n");
    fflush(stdout);
}
char finalop[10010];
int finalen;
void inse(char s)
{
    finalop[finalen++]=s;
}
void inser(char* s)
{
    int inlen=strlen(s);
    for(int i=0;i<inlen;++i)    inse(s[i]);
}
void defau()
{
    finalen=0;
    inser("cd ");
    for(int i=1;i<=top;++i)
    {
        inse('/');
        inser(sta[i].chr);
    }
    inser(" && ");
}
void conduc()
{
    finalop[finalen]='\0';
    int res=system(finalop);
    if(!res)    printf("指令成功执行！\n");
    else    printf("指令执行失败！\n");
    fflush(stdout);
}
char op[10010];
int oplen;
void cd()
{
    int begining=2;
    while(begining<oplen&&op[begining]==' ')    ++begining;
    if(begining==oplen)
    {
        printf("指令无效！\n");
        fflush(stdout);
        return;
    }
    if(op[begining]=='/')
    {
        len=0;
        for(int i=begining;i<oplen;++i) now[len++]=op[i];
        nwadd();
        printf("指令执行成功！\n");
        fflush(stdout);
        return;
    }
    ++top;
    sta[top]=emp;
    for(int i=begining;i<oplen;++i)
    {
        if(i+1<oplen&&op[i]=='.'&&(op[i-1]=='/'||i==begining)&&op[i+1]=='.'&&(i+2==oplen||op[i+2]=='/'))
        {
            top-=2;
            ++i;
        }
        else if(op[i]=='/')
        {
            ++top;
            sta[top]=emp;
        }
        else    sta[top].chr[sta[top].len++]=op[i];
    }
    printf("指令执行成功！\n");
    fflush(stdout);
}
void nm()
{
    defau();
    inser(op);
    conduc();
}
char po[10010];
int polen;
void cp()
{
    printf("请输入要复制的文件（夹）的路径：");
    fflush(stdout);
    gets(op);
    oplen=strlen(op);
    printf("请输入目的路径：");
    fflush(stdout);
    gets(po);
    polen=strlen(po);
    defau();
    inser("cp -rf ");
    inser(op);
    inse(' ');
    inser(po);
    conduc();
}
void rm()
{
    printf("请输入要删除的文件（夹）的路径：");
    fflush(stdout);
    gets(op);
    oplen=strlen(op);
    defau();
    inser("rm -rf ");
    inser(op);
    conduc();
}
void zp()
{
    printf("请输入要压缩的文件（夹）的路径：");
    fflush(stdout);
    gets(op);
    oplen=strlen(op);
    printf("请输入要压缩后的文件名：");
    fflush(stdout);
    gets(po);
    polen=strlen(po);
    defau();
    inser("tar -czf ");
    inser(po);
    inse(' ');
    inser(op);
    conduc();
}
void uzp()
{
    printf("请输入要解压的文件路径：");
    fflush(stdout);
    gets(op);
    oplen=strlen(op);
    defau();
    inser("tar -zxf ");
    inser(op);
    conduc();
}
int main()
{
    init();
    while(1)
    {
        printf("此程序用于文件管理，可实现文件的复制、删除、压缩、解压和其他指令操作。\n");
        printf("现在位置：");
        outputnow();
        printf("请输入Linux命令行指令，若要使用复制、删除、压缩、解压功能可输入1、2、3、4进入，输入exit退出程序。\n");
        fflush(stdout);
        gets(op);
        oplen=strlen(op);
        if(oplen==1)
        {
            if(op[0]=='1')
            {
                cp();
                continue;
            }
            else if(op[0]=='2')
            {
                rm();
                continue;
            }
            else if(op[0]=='3')
            {
                zp();
                continue;
            }
            else if(op[0]=='4')
            {
                uzp();
                continue;
            }
        }
        else if(oplen>=4&&op[0]=='e'&&op[1]=='x'&&op[2]=='i'&&op[3]=='t')   break;
        else if(oplen>=2&&op[0]=='c'&&op[1]=='d') cd();
        else    nm();
    }
    return 0;
}