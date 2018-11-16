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
    //------------------
      Question d0("Koi ot trite metoda na razpolagane na blokove ot operativnata pamet se implementira nai-lesno(izberete edno)?");
    d0.AddOption("Direktno supostavqne", 0);
    d0.AddOption("Pulna asociativnost", 0);
    d0.AddOption("Mnojestvena asociativnost", 0);
    exam.push_back(d0);
    
    Question d1("Otbelejete nevqrnoto tvurdenie(izberete edno).");
    d1.AddOption("Dlavnata (DRAM) pamet e po-bavna ot SRAM pametta", 0);
    d1.AddOption("DRAM konsumira po-malko energiq ot SRAM", 0);//tuka rusalchoto go smeni,moje i da e greshno
    d1.AddOption("Cache pametta e malka,burza i SRAM bazirana", 0);
    d1.AddOption("SRAM e po-evtina ot DRAM", 0);
    exam.push_back(d1);
    
    Question d2("Kakva e korelaciqta kapacitet i burzodeistvie pri kompiyturnite pameti(izberete edno)?");
    d2.AddOption("Proporcionalna", 0);
    d2.AddOption("Obratnoproporcionalna", 0);//verniqt
    d2.AddOption("Nqma korelaciq", 0);
    exam.push_back(d2);
   
    Question d3("Kakuv e formata na liniqta pri Cache pametta s mnojestvena acociativnost(izberete edno)?");
    d3.AddOption("tag,duma", 0);
    d3.AddOption("tag,liniq,duma", 0);
    d3.AddOption("tag,mnojestwo,duma", 0);//verniqt
    exam.push_back(d3);
    
    Question d4("Koi vid pameti sa po-burzi ot Cache pametite(izberete edno)?");
    d4.AddOption("Registrite", 0);//tova e verniqt otgovor
    d4.AddOption("Flash pametite", 0);
    d4.AddOption("Glavnata pamet", 0);
    exam.push_back(d4);
    
    Question d5("Metodut pri koito obnovqvane na glavnata pamet nastupva asinhronno sled premahvane na duma ot Cache se naricha(izberete edno)?");
    d5.AddOption("Zashtiten zapis", 0);
    d5.AddOption("Write-back", 0);//verniqt
    d5.AddOption("Cache-write", 0);
      d5.AddOption("Write-trough", 0);
    exam.push_back(d5);
    
    Question d6("Kakva e formata na liniqta pri Cache pamet s pulna asociativnost (izberete edno)?");
    d6.AddOption("tag,liniq,duma", 0);
    d6.AddOption("tag,duma", 0);
    d6.AddOption("tag,mojestvo,duma", 0);
    exam.push_back(d6);
    
    Question d7("Dadena e mashina s pobaitovo adresiruema osnovna pamet s razemr 2^16 baita,i razmer na bloka 8 baita.Cache pametta e s \ndirektna organizaciai se sustoi ot 32 linii.Kakuv e maksimalniqt broi baitove, koito mogat da budat razpolojeni w Cache pametta?(izberete edno)?");
    d7.AddOption("256B", 0);//verniqt
    d7.AddOption("1024B", 0);
    d7.AddOption("512B", 0);
     d7.AddOption("128B", 0);
     d7.AddOption("64B", 0);
    exam.push_back(d7);
    
    Question d8("LFU e algoritumut za(izberete edno)?");
    d8.AddOption("zamestvane na nai-chesto izpolzvanata stranica ot Cache pametta ", 0);
    d8.AddOption("zamestvane na nai-neizpolzwanata stranica v Cache pametta", 0);//veren
    d8.AddOption("zamestvane na nqkoi ot izpolzvanite stranici v Cache pametta", 0);
     d8.AddOption("periodichno izchistvane priznacite za obrushtenie kum nai-rqdko izpolzvanite stranici v Cache pametta.", 0);
    exam.push_back(d8);
    
     Question d9("Dadena e mashina s pobaitowo adresiruema osnovna pamet i 2-kraten mnojestveno asociativen Cache. Cache-logikata interpretira adresa ot pametta\nkakto sledva :14 bita za tag, 8 nita za mnojestvo,2 bita za adresirane na duma\n.Kolko e maksimalniq broi na blokovete v glavnata pamet?(izberete edno)?");
    d9.AddOption("Ne moje da bude opredelen", 0);
    d9.AddOption("2^2", 0);
    d9.AddOption("2^8", 0);
     d9.AddOption("2^22", 0);//veren
     d9.AddOption("2^14", 0);
       d9.AddOption("2^24", 0);
    exam.push_back(d9);
    
     Question d10("Cache pamet s asociativna organizaciq e s kapacitet 64 linii,pazdeleni na mnojestva s po 16 linii vsqko.Osnovnata pamet sudurja 4K bloka s po128 dumi vseka.\nPosochete adresniqt format ,koito i suotvetstva:(Formata e : tag,set,word)(izberete edno)?");
    d10.AddOption("8 2 7", 0);//towa bi trqbwalo da e vqrno , but who knows, definitely not Cvetanov
    d10.AddOption("14 8 4", 0);
    d10.AddOption("14 8 7", 0);
     d10.AddOption("4 8 7", 0);
    exam.push_back(d10);

      Question d11("Metodut,pri koito zapis na dannite se izvurshva samo v Cache pametta,a sustoqnieto na Cache-bloka se otbelqzva \nkato obiknoveno v ypravlqvashtoto pole s priznak,narechen \"update\" ili \"dirty\" se naricha :(izberete edno)?");
    d11.AddOption("Obraten zapis(Write back)", 0);
    d11.AddOption("Ednovremenen zapis(Write trough)", 0);
    exam.push_back(d11);
    
    Question d10("Cache pamet s asociativna organizaciq e s kapacitet 64 linii,pazdeleni na mnojestva s po 16 linii vsqko.Osnovnata pamet sudurja 4K bloka s po128 dumi vseka.\nPosochete adresniqt format ,koito i suotvetstva:(Formata e : tag,set,word)(izberete edno)?");
    d10.AddOption("8 2 7", 0);//towa bi trqbwalo da e vqrno , but who knows, definitely not Cvetanov
    d10.AddOption("14 8 4", 0);
    d10.AddOption("14 8 7", 0);
     d10.AddOption("4 8 7", 0);
    exam.push_back(d10);
    return 0;
}
