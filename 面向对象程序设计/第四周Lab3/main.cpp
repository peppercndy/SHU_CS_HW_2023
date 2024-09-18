// main.cpp
#include "Accout.h"
#include<vector>
//���Ժ�������ʼ������������
Accout create();

//�õ�Hero����ĵ������ݣ�׷�ӵ�ʱ��ʹ��
Data getHeroData();

//�õ�Accout����ĵ������ݣ�׷�ӵ�ʱ��ʹ��
AccoutData getAccoutData();

//�ڶ�������Hero�Ĳ˵���
void secondListMenu(Hero hero,int UID);

//��һ������Accout�Ĳ˵�
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
    // ����Data����
    /*
    Data datas[] = {
        {"��ά����", 70},
        {"����", 143},
        {"ܽ����", 2},
    };
    int n = sizeof(datas) / sizeof(*datas);


    Hero hero1(n, datas);
    hero1.showList();
    */
    // append�ĵ���
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
    // find�ĵ���
    hero1.find("����");
    */

}

Accout create(){
    //�ڶ��������һ��
    Data datas1[]{
        {"��ά����", 70},
        {"����", 143},
        {"ܽ����", 2},
    };
    int n = sizeof(datas1) / sizeof(*datas1);
    Hero hero1(n,datas1);

    //std::cout<<hero1.heronums();
    //�ڶ�������ڶ���
    Data datas2[]{
        {"��ά����", 122},
        {"������ŵ", 89},
        {"��ά�", 72},
        {"�����",36},
        {"������",110}
    };
    n = sizeof(datas2) / sizeof(*datas2);
    Hero hero2(n,datas2);

    //�ڶ������������
    Data datas3[]{
        {"ܽ����", 12},
        {"ҹ��", 66},
        {"����", 119},
        {"����",88},
        {"��ԭ��Ҷ",36},
        {"������",155}
    };
    n = sizeof(datas3) / sizeof(*datas3);
    Hero hero3(n,datas3);

    //�ڶ���������ĸ�
        Data datas4[]{
        {"ܽ����", 22},
        {"�����", 55},
        {"����", 136},
        {"����",133},
    };
    n = sizeof(datas4) / sizeof(*datas4);
    Hero hero4(n,datas4); 

//��һ������
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
    std::cout<<"�������³鵽��up���֣� ";
    std::cin>>name;
    std::cout<<std::endl<<"���������ĵ�ԭʯ�� ";
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
        std::cout<<"�����ڴ��ڵڶ��������У����˺ŵ�UIDΪ "<<UID<<" ���������书��ʵ�֣�"<<std::endl;
        std::cout<<std::endl<<"========== MENU =========="<<std::endl;
        std::cout<<" 1 ----������� up "<<std::endl;
        std::cout<<" 2 ----�ͷ����н��"<<std::endl;
        std::cout<<" 3 ----׷�� up ���"<<std::endl;
        std::cout<<" 4 ----��ѯ up ���"<<std::endl;
        //std::cout<<" 5 ----ɾ��ָ���˺�"<<std::endl;
        std::cout<<" 5 ----��ѯ up ����"<<std::endl;
        std::cout<<"========== MENU =========="<<std::endl;   
        std::cout<<std::endl<<"��ѡ������Ӧ�Ĳ������� ��0�� �˳� �� "; 
        int key{};
        std::cin>>key;
        if (key==0){
            std::cout<<"���˳����˺ŵĲ�ѯ��"<<std::endl;
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
                std::cout<<"��������Ҫ��ѯ��up�� ";
                std::cin>>name;
                hero.find(name);
                //Hero _hero=Hero(0,NULL);
                //accout.find(UID);
                //std::cout<<"�Ƿ�Դ��˺Ž��в�����y/n�� : ";
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
                std::cout<<"��������Ҫɾ�����˺�UID : ";
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
    std::cout<<"���濪ʼ¼���ºŵ����ݣ�"<<std::endl;
    std::cout<<"---------------"<<std::endl;
    std::cout<<"����������ºŵ�UID��"<<std::endl;
    int UID;
    std::cin>>UID;
    std::vector<Data> myVector{};
    while(true){
        myVector.push_back(getHeroData());
        std::cout<<"�Ƿ������� up (y/n): "<<std::endl;
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
        std::cout<<"�����ڴ��ڵ�һ������֮�У��������书��ʵ�֣�"<<std::endl;
        std::cout<<std::endl<<"========== MENU =========="<<std::endl;
        std::cout<<" 1 ----��������˺�"<<std::endl;
        std::cout<<" 2 ----�ͷ����н��"<<std::endl;
        std::cout<<" 3 ----׷���˺Ž��"<<std::endl;
        std::cout<<" 4 ----��ѯ�˺����"<<std::endl;
        std::cout<<" 5 ----ɾ��ָ���˺�"<<std::endl;
        std::cout<<" 6 ----��ѯ�˺�����"<<std::endl;
        std::cout<<"========== MENU =========="<<std::endl;
        std::cout<<std::endl<<"��ѡ������Ӧ�Ĳ������� ��0�� �˳� �� ";
        int key{};
        std::cin>>key;
        Hero _hero=Hero(0,NULL);
        if (key==0){
            std::cout<<"���˳����򣬻�ӭ�´�ʹ�ã�"<<std::endl;
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
                std::cout<<"��������Ҫ��ѯ��UID�� ";
                int UID;
                std::cin>>UID;
                //Hero _hero=Hero(0,NULL);
                _hero=accout.find(UID);
                std::cout<<"�Ƿ�Դ��˺Ž��в�����y/n�� : ";
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
                std::cout<<"��������Ҫɾ�����˺�UID : ";
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