#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
fstream word;
fstream mean;
typedef struct datatype
{
    string value;
    int length;
}elemtype;
typedef struct
{
    char index;
    int endlocal;
    int beginlocal;
}listelem;
class dictionary
{
    public: listelem indexlist[26];
    public: vector<elemtype> datalist;
    public: vector<string> meanlist;
    void ready(void)
    {
        //����26������;
        int i=0;
        char a='a';
        a=a-1;
        while(i<26)
        {
            a=a+1;
            this->indexlist[i].index=a;
            i++;
        }
        indexlist[0].beginlocal=0;
        //���ļ���ȡ����,���ҽ�����������
        elemtype data;
        int length=0;
        char target='a';
        int indexlocal=0;
        while(!word.eof())
        {
            word>>data.value;
            data.length=data.value.length();
            this->datalist.push_back(data);
            //������ֲ�ͬ����ĸ��ͷ��
            if(data.value[0]!=target)
            {
                indexlist[indexlocal].endlocal=length;
                indexlist[indexlocal+1].beginlocal=length;
                indexlocal++;
                target=indexlist[indexlocal].index;
            }
            length++;
        }
        indexlist[25].endlocal=length-1;
        mean.open("mean.cpp");
        string means;
        while(!mean.eof())
        {
            mean>>means;
            this->meanlist.push_back(means);
        }
        cout<<"�ֵ����ݵ���ɹ�,�뿪ʼ��Ĳ�ѯ����"<<endl;
        word.close();
        mean.close();
    };
    int searchword(string datavalue)
    {
        for(int i=0;i<26;i++)
        {
            if(datavalue[0]==this->indexlist[i].index)
            {
                int low=this->indexlist[i].beginlocal,high=this->indexlist[i].endlocal;
                int mid=(low+high)/2;
                while(low!=mid&&this->datalist[mid].value!=datavalue)
                {
                    if(this->datalist[mid].value<datavalue)
                    {
                        low=mid;
                        mid=(high+low)/2;
                    }
                    if(this->datalist[mid].value>datavalue)
                    {
                        high=mid;
                        mid=(high+low)/2;
                    }
                }
                if(this->datalist[mid].value==datavalue)
                {
                    cout<<this->meanlist[mid]<<endl;
                    return 0;
                }
                else
                {
                    cout<<"û�в鵽�������"<<endl;
                    return 0;
                }
            }
        }
    }
    int addword()
    {
        mean.open("means.cpp");
        word.open("data.cpp");
        string words,means;
        cout<<"��������Ҫ���Ӵ����ĵ��ʺ���������,��ͬ����֮���ö��Ż��߷ֺŷֿ�"<<endl;
        cin>>words;
        cin>>means;
        elemtype wordselem;
        int beginlocal,endlocal;
        int i;
        for(i=0;i<26;i++)
        {
            if(this->indexlist[i].index==words[0])
            {
                beginlocal=this->indexlist[i].beginlocal;
                endlocal=this->indexlist[i].endlocal;
                break;
            }
        }
        int low=beginlocal,high=endlocal;
        int mid=(low+high)/2;
        while(low!=mid&&this->datalist[mid].value!=words)
        {
            //���������ַ��ȵ�ǰ�Ƚ��ַ�λ�ÿ���
            if(this->datalist[mid].value<words)
            {
                low=mid;
                mid=(high+low)/2;
            }
            if(this->datalist[mid].value>words)
            {
                high=mid;
                mid=(low+high)/2;
            }
        }
        if(this->datalist[mid].value==words)
        {
            this->meanlist[mid]=means;
            cout<<"�޸ĳɹ�"<<endl;
            return 0;
        }
        wordselem.value=words;
        wordselem.length=words.length();
        this->datalist.insert(this->datalist.begin()+mid+1,wordselem);
        this->meanlist.insert(this->meanlist.begin()+mid+1,means);
        cout<<"��ӳɹ�"<<endl;
        this->indexlist[i].endlocal++;
        for(int j=i+1;j<26;j++)
        {
            this->indexlist[j].beginlocal++;
            this->indexlist[j].endlocal++;
        }
        mean.close();
        word.close();
        return 0;
    }
    void savedata(void)
    {
        fstream fixwords,fixmeans;
        string fixdata,fixmean;
        fixwords.open("data.cpp",ios::out);
        fixmeans.open("mean.cpp",ios::out);
        for(int i=0;i<this->datalist.size();i++)
        {
            fixdata=this->datalist[i].value;
            fixmean=this->meanlist[i];
            fixwords<<fixdata;
            fixwords<<" ";
            fixmeans<<fixmean;
            fixmeans<<" ";
        }
        fixwords.close();
        fixmeans.close();
    }
};
int main()
{
    string data;
    word.open("data.cpp");
    dictionary Dir;
    Dir.ready();
    Dir.addword();
    while(cin>>data)
    {
        Dir.searchword(data);
    }
    cout<<"ллʹ�ã��ټ�!"<<endl;
    Dir.savedata();
    return 0;
}
