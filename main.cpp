#include"jindutiao.h"
#include <mmsystem.h> // 用于播放音效
#pragma comment(lib, "winmm.lib") // 链接Windows多媒体库
const int WAIT=5;

struct Punish{	//惩罚结构体 
	string content;	//惩罚内容 
	int index;	//惩罚编号 
}; 

// 音效播放函数
void PlaySoundEffect(const string& soundType){
    if(soundType=="drumroll"){
        PlaySound(TEXT("SystemExclamation"),NULL,SND_ALIAS|SND_ASYNC); // 鼓声音效，用于制造悬念
    }else if(soundType=="reveal"){
        PlaySound(TEXT("SystemAsterisk"),NULL,SND_ALIAS|SND_ASYNC); // 揭示音效，惩罚内容展示时使用
    }else if (soundType=="celebration"){
        PlaySound(TEXT("SystemQuestion"),NULL,SND_ALIAS|SND_ASYNC); // 庆祝音效，惩罚结束时使用
    }else if (soundType=="error"){
        MessageBeep(MB_ICONERROR); // 错误音效
    }else if (soundType=="success"){
        MessageBeep(MB_ICONASTERISK); // 成功音效
    }
}

vector<Punish> vecPunishList={	//惩罚列表 
	{"黑板清洁工：擦一节课的黑板",1},
	{"失败发布会：用1分钟时间，面向全班，煞有介事地推介一款根本不存在（或极其愚蠢）的“数字产品”\n\t  例如：“隆重推出我的革命性产品：一款为宠物猫设计的键盘，只有‘饿’和‘撸我’两个键！”",2},
	{"代码朗读机：用最饱满的感情、最戏剧化的语调将老师的提供一段枯燥无比、满是嵌套循环和复杂条件的代码大声朗读出来",3},
	{"我是小模特：用大头照作为课间时大屏幕上的背景",4},
	{"B u g 之舞：到教室前方，用身体动作模拟一个经典的软件B u g \n\t  例如：表演“无限循环”（原地转圈不止）、“内存溢出”（身体僵硬膨胀然后倒地）、\n\t        “404错误”（疯狂做找不到东西的动作）。",5},
	{"我是小演员：模仿一个鬼畜视频10秒",6},
	{"我是歌唱家：唱一首歌曲，要大声响亮，不少于30秒",7},
	{"旁白解说员：为一段非常无聊的代码运行过程配旁白解说，必须使用体育赛事解说员般的激情：\n\t  “观众朋友们！看！又一个变量被声明了！它进去了！进入了循环体！噢！这是一个漂亮的if判断！它成功了！”",8},
	{"反向推销者：当一个“反向推销者”，用1分钟时间，极力说服大家放弃使用本节课要学的编程语言或工具，\n\t  并言之凿凿地罗列它的“缺点”（即使是这些缺点是编的）",9},
	{"小小说书人：用一分钟时间向大家分享一个关于守时重要性的小故事或名言警句",10},
	{"我是编译器：另一位同学（或老师）说一句简单的自然语言指令\n\t   （如：“帮我把a和b两个变量交换一下”），迟到者必须用身体动作和拟声词把这个编译和执行的过程表演出来。",11},
	{"一个复读机：迟到者必须完美复刻一位老师或某位同学的标志性动作、口头禅或习惯（必须是善意的模仿），\n\t  直到全班大部分人都猜出模仿的是谁。",12},
	{"蓝屏模仿者：迟到者必须模仿经典的Windows10蓝屏死机界面。\n\t   他需要突然僵住，然后缓缓面朝上倒地（注意安全，可以是缓慢的“软倒地”），同时用毫无感情的语调念出：\n\t  “你的设备遇到问题，需要重启。我们只收集某些错误信息，然后为你重新启动。”",13},
	{"屎山程序员：迟到者扮演一个油嘴滑舌、过度承诺的“屎山代码推销员”。\n\t   他需要向全班激情推销一段自己写过的（或者老师提供的）最烂、最屎山的代码，\n\t   并吹嘘其拥有“颠覆性创新”、“区块链加持”、“AI驱动”等根本不存在的功能。",14},
	{"加载中图标：迟到者必须走到教室角落，选择一个地方，双手举过头顶并拢，开始原地缓慢旋转，\n\t   模拟网页加载中的旋转图标。他必须一边旋转一边说：“正在加载……”，直到持续满2分钟为止。",15},
	{"IT支持热线：一位同学扮演一个对电脑一窍不通的暴躁用户，打电话给“IT支持”（迟到者）。\n\t   迟到者必须用最耐心、最专业的口吻，指导同学完成一个极其荒谬的任务，\n\t   例如：“如何用代码给咖啡降温？”或“我的鼠标指针不见了，如何用命令行找回来？”",16},
	{"表情包生成：其他同学说出一个著名的网络表情包名字（如“捂脸”、“笑哭”、“狗头”），\n\t   迟到者必须在3秒内用自己的脸和身体模仿出该表情包的经典动作和神态，并由其他同学拍照“存档”。",17},
	{"重启小剧场：迟到者需要表演一套完整的“电脑重启”流程：\n\t   先是卡顿（动作迟缓），然后蓝屏（参见惩罚:蓝屏模仿者），接着是关机（完全倒地静止5秒），\n\t   最后是开机音乐响起（自己哼唱“登~登登-登登”），活力满满地“重新启动成功”。",18},
	{"变量名哲学：迟到者从TA之前写过的代码中随机挑一个变量名（比如 a, temp, qqq），让他面向全班，\n\t   用1分钟时间解释这个变量名的深层哲学含义、起名时的心路历程以及它对于整个宇宙的意义。",19},
	{"首席道歉官:迟到者需模仿大型科技公司CEO开发布会道歉的架势，走到台前，双手撑住讲台，面色沉重地说：\n\t   “今天，我们团队（指自己）在准时交付（指上课）上出现了不可接受的延迟，这不符合我们追求极致的价值观。\n\t   我们已成立专项工作组（指自己的大脑），深刻复盘，杜绝此类事件再次发生...”",20}
};

void FlashScreen(int times=3, int delay=200){
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    WORD originalAttributes=csbi.wAttributes;
    
    for(int i=0;i<times;i++){
        // 闪烁效果
        SetConsoleTextAttribute(hConsole,BACKGROUND_RED|BACKGROUND_INTENSITY);
        Sleep(delay);
        SetConsoleTextAttribute(hConsole,originalAttributes);
        Sleep(delay);
    }
}

void TypewriterEffect(const string& text,int speed=50,bool withSound=true){
    for (char c:text){
        cout<<c;
        if(withSound){
            Beep(500,30); // 打字机音效
        }
        Sleep(speed);
    }
}

void AnimatePunishmentReveal(const string& name, const string& punishment){
    system("cls");
    
    // 播放鼓声音效
    PlaySoundEffect("drumroll");
    
    // 显示谁将被惩罚
    cout << "\n\n\t\t";
    TypewriterEffect("接下来接受惩罚的是：",70);
    
    // 名字显示特效
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);
    cout << "\n\n\t\t\t";
    for (char c:name){
        cout<<c;
        Sleep(100);
    }
    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout<<"\n\n\t\t";
    TypewriterEffect("TA的惩罚是...",100);
    
    // suspense
    for (int i=0;i<3;i++){
        cout<<".";
        Sleep(500);
    }
    
    // 屏幕闪烁效果
    FlashScreen(3,150);
    
    // 播放揭示音效
    PlaySoundEffect("reveal");
    
    // 显示惩罚内容
    cout<<"\n\n\t\t";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    TypewriterEffect(punishment,30, true);
    
    // 播放庆祝音效
    PlaySoundEffect("celebration");
    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    cout<<"\n\n\n";
    system("pause");
}

void DisplayPunishmentSummary(const vector<pair<string,string>>& punishments){
    system("cls");
    
    // 播放成功音效
    PlaySoundEffect("success");
    
    cout<<"===================================="<<endl;
    cout<<"          惩罚总结列表"<<endl;
    cout<<"===================================="<<endl;
    
    for (size_t i=0;i<punishments.size();++i){
        cout<<i+1<<". "<<punishments[i].first <<" - "<<punishments[i].second<<endl;
        // 每个条目显示时的轻微提示音
        Beep(800,20);
        cout<<"------------------------------------"<<endl;
    }
    
    cout<<"\n\n";
    system("pause");
}

void outputList(vector<Punish>& punish){	//输出惩罚列表 
	for(auto it=punish.begin();it<punish.end();it++){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);
		cout<<'\t'<<it->index<<'.';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
		cout<<it->content<<endl<<endl; 
	}
}

void sout_slower(string s,int speed,int addedWait){
	for(int i=0;i<s.length();i++){
		cout<<s[i];
		lt.HpSleep(speed+addedWait*i);
	}
}

void Punished(int num,vector<Punish>& punish){
	int people,array[num+1]={0},dice_roll;
	system("cls"); 
	system("color 74");
	cout<<"有多少人要受惩罚：";
	cin>>people;
	// 输入错误处理
    if(cin.fail()||people<=0){
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        PlaySoundEffect("error"); // 播放错误音效
        cout<<"输入错误！请重新运行程序。"<<endl;
        Sleep(2000);
        return;
    }
    
    vector<string> name(people);
    if(people>0){
        int i=1;
        for(auto& n:name){
            cout<<"请输入第"<<i<<"个人的人名：";
            cin>>n;
            i++;
        }
    }else{
        PlaySoundEffect("error"); // 播放错误音效
        cout<<"你输入的人数错误！"<<endl;
        Sleep(2000);
        return;
    }
	
	// 存储所有惩罚结果的向量
    vector<pair<string, string>> allPunishments;
	system("color 07");
	mt19937 engine;
	uniform_int_distribution<int> dist(1, num);
	random_device rd;
	engine.seed(rd());
	for(int i=0;i<min(people,num);++i){
        do{
            dice_roll=dist(engine);
        }while(array[dice_roll]);
        array[dice_roll]=1;
        // 记录惩罚结果
        allPunishments.push_back({name[i],punish[dice_roll-1].content});
        // 使用新的动画效果显示惩罚
        AnimatePunishmentReveal(name[i],punish[dice_roll-1].content);
    }
    if(people>num) {
        for(int i=num;i<people;++i){
            dice_roll=dist(engine);
            // 记录惩罚结果
            allPunishments.push_back({name[i], punish[dice_roll - 1].content});

            // 使用新的动画效果显示惩罚
        	AnimatePunishmentReveal(name[i], punish[dice_roll-1].content);
        }
    }
    
    // 显示惩罚总结列表
    DisplayPunishmentSummary(allPunishments);
} 

int main(){
	// 程序开始音效
    Beep(600, 200);
    Beep(800, 200);
	
	jindutiao.Jindutiao(70,200,0,0,' ',' ',"加载","low"); 
	
	system("title Punish-Project 1.8");
	system("color 03");
	cout<<"******************************"<<endl;
	cout<<"*         惩罚小程序         *"<<endl;
	cout<<"*     让迟到的同学爽翻天     *"<<endl;
	cout<<"******************************"<<endl;
	cout<<"\t\tMade by LovelyYoung"<<endl; 
	
	// 提示音
    Beep(1000, 100);
	
	lt.DIYpause("请按下任意键，开启爽翻之旅……");
	
	 // 页面切换音效
    Beep(500, 50);
	while(true){
		system("cls"); 
		system("color 07");
		cout<<"请选择（输入对应的数字）："<<endl;
		cout<<"1.使用内设的惩罚（"<<vecPunishList.size()<<"个）" <<endl;
		outputList(vecPunishList);
		cout<<"2.在内设的惩罚的基础上追加惩罚"<<endl;
		cout<<"3.选择几项内设的惩罚并追加惩罚"<<endl;
		cout<<"4.自己输入惩罚"<<endl;
		cout<<"5.退出程序"<<endl;
		int in;
		cin>>in;
		
		// 选择音效
	    Beep(800, 100);
		
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
					// 添加成功音效
	                PlaySoundEffect("success");
				}else{
					PlaySoundEffect("error");
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
			        PlaySoundEffect("success");
				}
				if(cf1>0&&cf3>0){
					Punished(vecPunishList2.size(),vecPunishList2);
				}else{
					PlaySoundEffect("error");
					cout<<"没有选择任何惩罚！"<<endl;
					Sleep(2000);
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
						if(i>10){
							Beep(600 + 10 * 50, 50); // 输入进度音效
						}else{
							Beep(600 + i * 50, 50); // 输入进度音效
						}
					}
					PlaySoundEffect("success");
					Punished(vecPunishList3.size(),vecPunishList3);
				}else{
					PlaySoundEffect("error");
					cout<<"你没有输入惩罚。"<<endl;
					Sleep(2000);
				}
				break;
			}
			case 5:{
				// 程序结束音效
			    Beep(800,200);
			    Beep(600,200);
				
				lt.DIYpause("请按下任意键，结束这个可恶的程序……");
				return 0;
			}
			default:{
				PlaySoundEffect("error");
				cout<<"你是熊孩子吗？在这乱点乱按！"<<endl;
				Sleep(2000);
				break;
			}
		}
	}
}
