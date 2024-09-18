// main.cpp
#include "Accout.h"
#include<vector>
//测试函数，初始化这两层链表
Accout create();

//得到Hero链表的单个数据，追加的时候使用
Data getHeroData();

//得到Accout链表的单个数据，追加的时候使用
AccoutData getAccoutData();

//第二层链表Hero的菜单。
void secondListMenu(Hero hero,int UID);

//第一层链表Accout的菜单
void firstListMenu();

int main() {
//9.18    
    firstListMenu();
    return 0;
//9.17
    /*
    Accout accout=create();
    accout.showAccoutList();
    return 0;
    */
//9.15
    // 构建Data数组
    /*
    Data datas[] = {
        {"那维莱特", 70},
        {"甘雨", 143},
        {"芙宁娜", 2},
    };
    int n = sizeof(datas) / sizeof(*datas);


    Hero hero1(n, datas);
    hero1.showList();
    */
    // append的调试
    /*
    string name;
    cin >> name;
    int stone;
    cin >> stone;
    Data data{name, stone};
    hero1.append(data);
    hero1.showList();
    */
   /*
    hero1.heronums();
    // find的调试
    hero1.find("甘雨");
    */

}

Accout create(){
    //第二层链表第一个
    Data datas1[]{
        {"那维莱特", 70},
        {"甘雨", 143},
        {"芙宁娜", 2},
    };
    int n = sizeof(datas1) / sizeof(*datas1);
    Hero hero1(n,datas1);

    //std::cout<<hero1.heronums();
    //第二层链表第二个
    Data datas2[]{
        {"那维莱特", 122},
        {"阿蕾奇诺", 89},
        {"娜维娅", 72},
        {"纳西妲",36},
        {"流浪者",110}
    };
    n = sizeof(datas2) / sizeof(*datas2);
    Hero hero2(n,datas2);

    //第二层链表第三个
    Data datas3[]{
        {"芙宁娜", 12},
        {"夜兰", 66},
        {"宵宫", 119},
        {"胡桃",88},
        {"枫原万叶",36},
        {"玛拉妮",155}
    };
    n = sizeof(datas3) / sizeof(*datas3);
    Hero hero3(n,datas3);

    //第二层链表第四个
        Data datas4[]{
        {"芙宁娜", 22},
        {"纳西妲", 55},
        {"林尼", 136},
        {"白术",133},
    };
    n = sizeof(datas4) / sizeof(*datas4);
    Hero hero4(n,datas4); 

//第一层链表
    AccoutData datas[]{
        {hero1,196026632},
        {hero2,304929684},
        {hero3,225318414},
        //{hero3,197567333},
        {hero4,167033637}
    };
    n=sizeof(datas)/sizeof(*datas);
    Accout accout(datas,n);
    return accout;
}

/*
    Hero(int n, const Data* datas);
    void showList();
    void freeList();
    void append(const Data& data);
    bool find(const std::string& name);
    int heronums() const;
*/
Data getHeroData(){
    std::string name;
    int stone;
    std::cout<<"请输入新抽到的up名字： ";
    std::cin>>name;
    std::cout<<std::endl<<"请输入消耗的原石： ";
    std::cin>>stone;
    return {name,stone};
}
void secondListMenu(Hero hero,int UID){
    //std::cout<<hero.heronums();
    std::string _judge;
    std::cin>>_judge;
    if (_judge=="n"){
        return ;
    }
    while(true){
        std::string name{};
        std::cout<<"您现在处于第二层链表中，此账号的UID为 "<<UID<<" ，下面是其功能实现："<<std::endl;
        std::cout<<std::endl<<"========== MENU =========="<<std::endl;
        std::cout<<" 1 ----输出所有 up "<<std::endl;
        std::cout<<" 2 ----释放所有结点"<<std::endl;
        std::cout<<" 3 ----追加 up 结点"<<std::endl;
        std::cout<<" 4 ----查询 up 情况"<<std::endl;
        //std::cout<<" 5 ----删除指定账号"<<std::endl;
        std::cout<<" 5 ----查询 up 数量"<<std::endl;
        std::cout<<"========== MENU =========="<<std::endl;   
        std::cout<<std::endl<<"请选择所对应的操作，按 “0” 退出 ： "; 
        int key{};
        std::cin>>key;
        if (key==0){
            std::cout<<"已退出此账号的查询。"<<std::endl;
            break;
        }
        switch(key)
        {
            case 1:
                hero.showList();
                //acco.showAccoutList();
                break;
            case 2:
                //accout.freeLink();
                hero.freeList();
                break;
            case 3:
                hero.append(getHeroData());
                //std::cout<<"case 3"<<std::endl;
                break;
            case 4:
                std::cout<<"请输入您要查询的up： ";
                std::cin>>name;
                hero.find(name);
                //Hero _hero=Hero(0,NULL);
                //accout.find(UID);
                //std::cout<<"是否对此账号进行操作（y/n） : ";
                //secondListMenu(_hero,UID);
                /*
                std::string _judge;
                std::cin>>_judge;
                if (_judge=="y"){
                    secondListMenu(hero);
                }
                */
                break;
            /*
            case 5:
                std::cout<<"请输入想要删除的账号UID : ";
                int _UID;
                std::cin>>_UID;
                //accout.deleteAccout(_UID);
                break;
            */
            case 5:
                hero.heronums();
                break;
        }
    }
}

AccoutData getAccoutData(){
    std::cout<<"下面开始录入新号的数据："<<std::endl;
    std::cout<<"---------------"<<std::endl;
    std::cout<<"请输入这个新号的UID："<<std::endl;
    int UID;
    std::cin>>UID;
    std::vector<Data> myVector{};
    while(true){
        myVector.push_back(getHeroData());
        std::cout<<"是否还有其他 up (y/n): "<<std::endl;
        std::string judge{};
        std::cin>>judge;
        if(judge=="n"){
            break;
        }
    }
    Data myData[myVector.size()];
    for(size_t i=0;i<myVector.size();++i){
        myData[i]=myVector.at(i);
    }
    Hero link=Hero(myVector.size(),myData);
    return {link,UID};
}

void firstListMenu(){
    Accout accout=create(); 
    //AccoutNode newAccout=
    //AccoutData newAccout=AccoutData(0,)
    //std::cout<<accout.find(196026632).heronums()<<std::endl;
    //std::cout<<accout.find(196026632).heronums()<<std::endl;
    while(true){
        std::cout<<"您现在处于第一层链表之中，下面是其功能实现："<<std::endl;
        std::cout<<std::endl<<"========== MENU =========="<<std::endl;
        std::cout<<" 1 ----输出所有账号"<<std::endl;
        std::cout<<" 2 ----释放所有结点"<<std::endl;
        std::cout<<" 3 ----追加账号结点"<<std::endl;
        std::cout<<" 4 ----查询账号情况"<<std::endl;
        std::cout<<" 5 ----删除指定账号"<<std::endl;
        std::cout<<" 6 ----查询账号数量"<<std::endl;
        std::cout<<"========== MENU =========="<<std::endl;
        std::cout<<std::endl<<"请选择所对应的操作，按 “0” 退出 ： ";
        int key{};
        std::cin>>key;
        Hero _hero=Hero(0,NULL);
        if (key==0){
            std::cout<<"已退出程序，欢迎下次使用！"<<std::endl;
            break;
        }
        switch(key)
        {
            case 1:
                accout.showAccoutList();
                break;
            case 2:
                accout.freeLink();
                break;
                /*
            case 3:
                AccoutNode newAccout= AccoutNode(getAccoutData());
                break;
                */
            case 4:
                std::cout<<"请输入您要查询的UID： ";
                int UID;
                std::cin>>UID;
                //Hero _hero=Hero(0,NULL);
                _hero=accout.find(UID);
                std::cout<<"是否对此账号进行操作（y/n） : ";
                secondListMenu(_hero,UID);
                /*
                std::string _judge;
                std::cin>>_judge;
                if (_judge=="y"){
                    secondListMenu(hero);
                }
                */
                break;
            case 5:
                std::cout<<"请输入想要删除的账号UID : ";
                int _UID;
                std::cin>>_UID;
                accout.deleteAccout(_UID);
                break;
            case 6:
                accout.accoutnums();
                break;
        }
        if(key==3){
            AccoutNode newAccout= AccoutNode(getAccoutData());
            accout.append(newAccout);
        }
    }
}