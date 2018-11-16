#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <string>
struct Option
{
    Option(const std::string&, const double);
    double val = 0;
    std::string text;
};
Option::Option(const std::string& txt, const double val): text(txt), val(val)
{
}
class Question
{
public:
    Question(const std::string&);
    void AddOption(const std::string&, const double);
    void AskQuestion();
    void AnswerQuestion();
private:
    std::string m_Question;
    std::vector<Option>m_Answers;
    double m_Score = 0;
};
void Question::AddOption(const std::string& rhs, const double val)
{
    Option opt(rhs, val);
    m_Answers.push_back(opt);
}
Question::Question(const::std::string& task) : m_Question(task)
{
}
int Randomize(const int i)
{
    return std::rand()%i;
}
void Question::AskQuestion()
{
    std::cout<<m_Question<<'\n';
    std::srand(unsigned(std::time(0)));
    for(unsigned i =0; i<m_Answers.size(); ++i)
        std::swap(m_Answers[Randomize(m_Answers.size())],m_Answers[Randomize(m_Answers.size())]);
    for(unsigned i =0; i<m_Answers.size(); ++i)
    {
        char ind = i+65;
        std::cout<<ind<<' '<<m_Answers[i].text<<'\n';
    }
}

void Question::AnswerQuestion()
{
    char tmp = 'v';
    unsigned tmpToInt;
    do{
        std::cin>>tmp;
        tmpToInt = tmp;
        if(tmpToInt<97)
            tmpToInt-=65;
        else
            tmpToInt-=97;
    m_Score+=m_Answers[tmpToInt].val;
    }while (tmp != 'q');
    std::cout<<"Your result is: "<<m_Score<<'\n';
}
int main()
{
    std::vector<Question> exam;
    Question q0("Dadena e mashina s pobaytovo adresiruema osnovna pamet 2^24 bayta i s kesh za danni s direktna organizaciq i s kapacitet 64k i 32 bajtovi blokove. Kolko bita sa neobhodimi za tag, blok i otmestvane?");
    q0.AddOption("8 bita za tag, 5 bita za blok, 11 bita za unikalna duma", 0);
    q0.AddOption("8 bita za tag, 11 bita za blok, 5 bita za unikalna duma", 0);
    q0.AddOption("11 bita za tag, 8 bita za blok, 5 bita za unikalna duma", 0);
    exam.push_back(q0);

    Question q1("Koi ot izbroenite podhodi sposobstvat za namalqvane na latentnostta pri zarejdane na danni v kesha?");
    q1.AddOption("Otlojen zapis na danni", 0);
    q1.AddOption("Zarejdane pri poiskvane", 0);
    q1.AddOption("Obraten zapis", 0);
    q1.AddOption("", 0);//cannot read
    q1.AddOption("", 0);//cannot read
    exam.push_back(q1);

    Question q2("Koy ot posochenite metodi ne e metod za preobrazuvane na virtualni adresi?");
    q2.AddOption("Metod na lokalnostta", 0);
    q2.AddOption("Metod na segmentno-stranchna organizaciq", 0);
    q2.AddOption("Metod na segmentna organizaciq", 0);
    q2.AddOption("Metod na stranichna organizaciq", 0);
    exam.push_back(q2);

    Question q3("Kolko e maksimalniqt broy stranici s razmer na stranicite 4k pri 32 bitov adres?");
    q3.AddOption("1M", 0);
    q3.AddOption("64k", 0);
    q3.AddOption("5k", 0);
    q3.AddOption("20k", 0);
    exam.push_back(q3);

    Question q4("Kakvo sudurja TLB pri stranichna organizaciq na pametta?");
    q4.AddOption("Momentna karta na sustoqnieto na stranicite na operativnata pamet", 1);
    q4.AddOption("Tablica s nomera na fizicheski stranici, prinadlejashti na daden proces", -1);
    q4.AddOption("Tablica s nomera na virtualni stranici, prinadlejashti na daden proces", -1);
    q4.AddOption("Tablica na stranicite na diska", -1);
    exam.push_back(q4);

    Question q5("Koq ot izbroenite harakteristiki ne opisva tablicata na stranicite?");
    q5.AddOption("Tablicata na stranicite se sustoi ot redove, vseki red ot tablicata suotvetstva na nomer na virtualna stranica", 0);
    q5.AddOption("Tablicata na stranicite sudurja informaciq za aktivnite procesi", 0);
    q5.AddOption("Tablicata na stranicite e dopulnena s bit za prisustvie, pokazvasht dali suotvetnata stranica se namira v svobodnata pamet", 0);
    q5.AddOption("Tablicata na stranicite se pazi nqkude v operativnata pamet", 0);
    exam.push_back(q5);

    return 0;
}
