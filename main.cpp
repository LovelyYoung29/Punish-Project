#include"jindutiao.h"
const int WAIT=5;

struct Punish{	//惩罚结构体 
	string content;	//惩罚内容 
	int index;	//惩罚编号 
}; 
vector<Punish> vecPunishList={	//惩罚列表 
	{"黑板清洁工：擦一节课的黑板",1},
	{"失败发布会：用1分钟时间，面向全班，煞有介事地推介一款根本不存在（或极其愚蠢）的“数字产品”",2},
	{"代码朗读机：用最饱满的感情、最戏剧化的语调将老师的提供一段枯燥无比、满是嵌套循环和复杂条件的代码大声朗读出来",3},
	{"我是小模特：用大头照作为课间时大屏幕上的背景",4},
	{"B u g 之舞：到教室前方，用身体动作模拟一个经典的软件B u g ",5},
	{"我是小演员：模仿一个鬼畜视频10秒",6},
	{"我是歌唱家：唱一首歌曲，要大声响亮，不少于30秒",7},
	{"旁白解说员：为一段非常无聊的代码运行过程配旁白解说，必须使用体育赛事解说员般的激情",8},
	{"反向推销者：当一个“反向推销者”，用1分钟时间，极力说服大家放弃使用本节课要学的编程语言或工具，并言之凿凿地罗列它的“缺点”（即使是这些缺点是编的）",9},
	{"小小说书人：用一分钟时间向大家分享一个关于守时重要性的小故事或名言警句",10}
};
void outputList(vector<Punish>& punish){	//输出惩罚列表 
	for(auto it=punish.begin();it<punish.end();it++){
		cout<<'\t'<<it->index<<'.'; 
		lt.Sout(it->content,WAIT);
		cout<<endl;
	}
}

void sout_slower(string s,int speed,int addedWait){
	for(int i=0;i<s.length();i++){
		cout<<s[i];
		Sleep(speed+addedWait*i);
	}
}

void Punished(int num,vector<Punish>& punish){
	int people,array[num+1]={0},dice_roll;
	system("cls"); 
	system("color 74");
	cout<<"有多少人要受惩罚：";
	cin>>people;
	vector<string> name(people);
	if(people>0){
		int i=1;
		for(auto &n:name){
			cout<<"请输入第"<<i<<"个人的人名：";
			cin>>n;
			i++;
		}
	}else{
		cout<<"你输入的人数错误！"<<endl; 
		return;
	}
	mt19937 engine;
	uniform_int_distribution<int> dist(1, num);
	random_device rd;
	engine.seed(rd());
	for(int i=0;i<min(people,num);++i){
        do{
            dice_roll=dist(engine);
        }while(array[dice_roll]);
        array[dice_roll]=1;
        sout_slower(name[i],50,5);
        sout_slower("的惩罚是：",50,60);
        lt.Sout(punish[dice_roll-1].content,5);
        cout<<endl;
    }
    if(people>num) {
        for(int i=num;i<people;++i) {
            dice_roll=dist(engine);
            sout_slower(name[i],50,5);
        	sout_slower("的惩罚是：",50,60);
        	lt.Sout(punish[dice_roll-1].content,5);
        	cout<<endl;
        }
    }
} 

int main(){
	jindutiao.Jindutiao(70,200,0,0,' ',' ',"加载","low"); 
	system("title Punish-Project 1.4.3");
	system("color 03");
	cout<<"******************************"<<endl;
	cout<<"*         惩罚小程序         *"<<endl;
	cout<<"*     让迟到的同学爽翻天     *"<<endl;
	cout<<"******************************"<<endl;
	cout<<"\t\tMade by LovelyYoung"<<endl; 
	lt.DIYpause("请按下任意键，开启爽翻之旅……");
	system("cls"); 
	system("color 07");
	cout<<"请选择（输入对应的数字）："<<endl;
	cout<<"1.使用内设的惩罚（10个）" <<endl;
	outputList(vecPunishList);
	cout<<"2.在内设的惩罚的基础上追加惩罚"<<endl;
	cout<<"3.选择几项内设的惩罚并追加惩罚"<<endl;
	cout<<"4.自己输入惩罚"<<endl;
	int in;
	cin>>in;
	switch(in){
		case 1:{
			Punished(vecPunishList.size(),vecPunishList);
			break;
		}
		case 2:{
			cout<<"请问你要输入多少个惩罚：";
			int cf;
			cin>>cf;
			if(cf>0){
				cout<<"请输入你的惩罚:\n";	
				for(int i=0;i<cf;i++){
					cout<<"请输入惩罚"<<i+1<<":"; 
		            Punish p;
		            cin.ignore(); // 清除输入缓冲区
                    getline(cin, p.content);
		            p.index = vecPunishList.size() + 1; // 设置新惩罚的索引
		            vecPunishList.push_back(p);
				}
			}
			Punished(vecPunishList.size(),vecPunishList);
			break;
		}
		case 3:{
			cout<<"请问你要选择几个惩罚:";
			int cf1;
			cin>>cf1;
			vector<Punish> vecPunishList2;
			if(cf1>0){
				cout<<"请分别输入它们的编号：";
				int cf2[cf1];
				for(int i=0;i<cf1;i++){
					cin>>cf2[i];
					vecPunishList2.push_back(vecPunishList[cf2[i]-1]);
				}
			}
			cout<<"请问你要输入多少个惩罚：";
			int cf3;
			cin>>cf3;
			if(cf3>0){
				cout<<"请输入你的惩罚:\n"; // 这里提示输入惩罚内容
		        for(int i=0;i<cf3;i++){
		        	cout<<"请输入惩罚"<<i+1<<":"; 
		            Punish p;
		            cin.ignore(); // 清除输入缓冲区
                    getline(cin, p.content);
		            p.index = vecPunishList2.size() + 1; // 设置新惩罚的索引
		            vecPunishList2.push_back(p);
		        }
			}
			if(cf1>0&&cf3>0){
				Punished(vecPunishList2.size(),vecPunishList2);
			}else{
				cout<<"没有选择任何惩罚！"<<endl;
			} 
			break;
		}	
		case 4:{
			cout<<"请问你要输入多少个惩罚：";
			int cf4;
			cin>>cf4;
			if(cf4>0){
				cout<<"请输入你的惩罚:\n";
				vector<Punish> vecPunishList3(cf4); 
				cin.ignore(); // 清除输入缓冲区
				for(int i=0;i<cf4;i++){
					cout<<"请输入惩罚"<<i+1<<":"; 
					getline(cin, vecPunishList3[i].content);
					vecPunishList3[i].index=i+1;
				}
				Punished(vecPunishList3.size(),vecPunishList3);
			}else{
				cout<<"你没有输入惩罚。"<<endl;
			}
			break;
		}
		default:{
			cout<<"你是熊孩子吗？在这乱点乱按！"<<endl;
			break;
		}
	} 
	lt.DIYpause("请按下任意键，结束这个可恶的程序……");
	return 0;
}
