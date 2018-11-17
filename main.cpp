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
    std::cin>>tmp;
        tmpToInt = tmp;
    do
    {
        if(tmpToInt<97)
            tmpToInt-=65;
        else
            tmpToInt-=97;
        m_Score+=m_Answers[tmpToInt].val;
        std::cin>>tmp;
        tmpToInt = tmp;
    } while(tmp != 'q');
    std::cout<<"Your result is: "<<m_Score<<'\n';
}
int main()
{
    std::vector<Question> exam;

    //cache memory
    Question d0("Koi ot trite metoda na razpolagane na blokove ot operativnata pamet se implementira nai-lesno(izberete edno)?");
    d0.AddOption("Direktno supostavqne", 1);
    d0.AddOption("Pulna asociativnost", -1);
    d0.AddOption("Mnojestvena asociativnost", -1);
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

    Question d4("Koy vid pameti sa po-burzi ot Cache pametite(izberete edno)?");
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

    //virtual memory
    Question q11("Koy ot posochenite metodi ne e metod za preobrazuvane na virtualni adresi?");
    q11.AddOption("Metod na stranichna organizaciq", -1);
    q11.AddOption("Metod na segmentno-stranichna organizaciq", -1);
    q11.AddOption("Metod na lokalnostta", 1);
    q11.AddOption("Metod na segmentna organizaciq", -1);
    exam.push_back(q11);

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

    Question q6("Kakvo e prednaznachenieto na TLB?");
    q6.AddOption("Da minimizira zagubata na burzodeystvie pri tarsene na fizicheskoto razpolojenie na dannite", 1);
    q6.AddOption("Da preobrazuva virtualnite stranichni adresi vuv fizicheski", -1);
    q6.AddOption("Da namali proizvoditelnostta na harduerna implementaciq", -1);
    exam.push_back(q6);

    Question q7("Kakvi tipove pamet se izpolzvat za sahranenie i poddurjane na tablicite na stranicite pri statichna organizaciq na pametta?");
    q7.AddOption("Keshova s direktna organizaciq", -1);
    q7.AddOption("Asociativni keshove", 0.5);
    q7.AddOption("Mnojestveno asociativni keshove", 0.5);
    q7.AddOption("Vunshna diskova pamet", -1);
    q7.AddOption("Glavna pamet", -0.5);
    exam.push_back(q7);

    //addressing modes
    Question q8("Posochete za koy ot izbroenite rejimi na adresaciq se otnasq pokazanata figura\n|  kod |  operand |");
    q8.AddOption("Indeksna", -1);
    q8.AddOption("Kosvena", -1);
    q8.AddOption("Vlojena", -1);
    q8.AddOption("Neposredstvena", 1);
    exam.push_back(q8);

    Question q9("Kak se ukazva stoynostta na operanda pri registrov rejim na adresaciq?");
    q9.AddOption("Zadava se v koda na instrukciqta", -1);
    q9.AddOption("Zadava se chrez konstantno otmestvane sprqmo nachaloto na programniq segent", -1);
    q9.AddOption("S nomera na registara", 1);
    exam.push_back(q9);

    Question q10("Pri koy otizbroenite metodi na adresaciq v adresnata chast na instrukciqta e zapisan adresen ukazatel?");
    q10.AddOption("Indeksna adresaciq", -1);
    q10.AddOption("Direktna adresaciq", -1);
    q10.AddOption("Indirektna adresaciq s registri", -1);
    q10.AddOption("Neposredstvena adresaciq", -1);
    q10.AddOption("Indirektna adresaciq", 1);
    exam.push_back(q10);

    Question q12("Kude e mestopolojenieto na operanda pri registrovo kosvena adresaciq?");
    q12.AddOption("V registar", -1);
    q12.AddOption("V osnovnata pamet", 1);
    q12.AddOption("Vav vtorichnata pamet", -1);
    q12.AddOption("V koda na instrukciqta", -1);
    exam.push_back(q12);

    Question q13("Kak se kazva efektivniq adres na operanda v pametta pri neposredstven rejim na adresaciq?");
    q13.AddOption("Chrez adres na registar na mikroprocesora", -1);
    q13.AddOption("Chrez stekoviq ukazatel", -1);
    q13.AddOption("Chrez adresnoto pole na operanda v koda na instrukciqta", 1);
    exam.push_back(q13);

    //pipelining
    Question u7("Poso4ete pri konveyernata obrabotka na koq ot dadenite instrukcii posledovatelnostti vuznikvat hazart ot tipa write-after-read");
    u7.AddOption("ADD R3, R2, R1; R3 = R2 + R1", -1);
    u7.AddOption("ADD R3, R2, R1; R3=R2+R1  SUB R2, R3, 1; R2=R3-1  ADD R3, R2, R5; R3 = R2+R5", 1);
    u7.AddOption("ADD R3, R4, R5 SUB R2, R2, 1 BEQ R2, R0, L1", -1);
    exam.push_back(u7);

    Question u8("Znaeiki, 4e uskorenieto e pravoproporcionalno na broq fazi na konveyera, zasto realno polu4enoto uskorenie e po-malko v sravnenie s teoreti4no dostijimoto?");
    u8.AddOption("Zaradi hazartite", 0);
    u8.AddOption("Zaradi po-visokata patentnost za individualnite instrukcii", 0);
    u8.AddOption("Zaradi vremeto neobhodimo za zapulvane na konveyera", 0);
    exam.push_back(u8);

    Question u9("Razdelqneto na instrukciite na otdelni fazi na obrabotka e harakterno za:(izberete edno ili poveche)");
    u9.AddOption("razpredelenata obrabotka", 0);
    u9.AddOption("paralelnata obrabotka", 0);
    u9.AddOption("sistemnata obrabotka", 0);
    u9.AddOption("konveyernata obrabotka", 0);
    u9.AddOption("poddurjaneto na paralelizum na nivo instrukcii", 0);
    exam.push_back(u9);

    Question u10("Kolko mashinni cikula shte sa neobhodimi za konveyerna obrabotka na 1500 instrukcii v 5-fazen lineen instrukcionen konveyer?");
    u10.AddOption("1505", -1);
    u10.AddOption("7500", -1);
    u10.AddOption("18", -1);
    u10.AddOption("1504", 1);
    exam.push_back(u10);

    Question u11("Kak se preodolqvat hazartite v konveyera pri dostup do obshti resursu v instrukcionniq potok?(ibereze edno ili pove4e)");
    u11.AddOption("4rez prenarejdane na instrukcionniq potok ot kompilatora", 0);
    u11.AddOption("4rez predskazvane na prehodite v instrukcionniq potok", 0);
    u11.AddOption("4rez dublirane na kiriti4nite fazi", 0);
    u11.AddOption("4rez blokirasti tehniki na konveyera za opredeleno vreme i posledovatelna obrabotka", 1);
    u11.AddOption("4rez preska4ane na kriti4nite fazi", 0);
    u11.AddOption("4rez vuvejdane na zakusneniq i modifirane ...nata tablica na zaetost na konveyera", 1);
    exam.push_back(u11);

    Question u12("V instrukcionniq konveyer se izpulnqvat ednovremenno(izberete edno)");
    u12.AddOption("Prazni instrukcii", 0);
    u12.AddOption("Instrukcii za usloven i bezusloven prehod", 0);
    u12.AddOption("Instrukcii v realni fazi", 1);
    u12.AddOption("Zapisi na danni ot registrite kim procesora", 0);
    exam.push_back(u12);

    Question u13("Koi ot izbroenite tehniki se izpolzvat pri razreshavaneto na problemi pri konveyernoto izpulnenie na instrukcii s prehod? (izberete edno ili pove4e)");
    u13.AddOption("Dublirane na konveyernite resursi", 0);
    u13.AddOption("Mnojestveno predvaritelno izpulvane na instrukcii(ne se 4ete)", 1);
    u13.AddOption("Prediction Look-up Table", 0);
    u13.AddOption("Izpolzvane na specializirani funkcionalni ustroistva za 4etene na operaciite ili zapis na rezultatite v pametta", 0);
    u13.AddOption("BTB bufer", 0);
    exam.push_back(u13);

    Question u14("Kak se preodolqvat konfliktite za pamet pri konveyeriziranoto izpulnenie na instrukcionniq potok?");
    u14.AddOption("4rez vuvejdane na zakusneniq i modificirane izhodnata tablica na zaetost na konveyera ", 0);
    u14.AddOption("4rez predskazvane na prehodite v instrukcionniq potok", 1);
    u14.AddOption("4rez prenarejdane na instrukcionniq potok ot kompilatora", 0);
    u14.AddOption("4rez izpolzvane na specializirano funkcionalno ustroistvo za 4etene na operaciite ili zapis na rezultati v pametta", 0);
    exam.push_back(u14);

    Question u15("Poso4ete koi ot izbroenite faktori sa ri4ina za ponijavane na potokovata skorost pri konveyernata obrabotka (izberete edno ili pove4e)");
    u15.AddOption("Zavisimosti po danni", 1);
    u15.AddOption("Predskazvane na prehoda v informacionniq potok", 0);
    u15.AddOption("Temp na inicializaciq na konveyera", 0);
    u15.AddOption("Konflikti pri dostup na obshti resursi", 1);
    u15.AddOption("Patentnost na konveyernata obrabotka", 0);
    u15.AddOption("Izpolzvaemost na funkcionalnite ustroistva po konveyera", 0);
    u15.AddOption("Anti-zavisimosti po danni", 1);
    u15.AddOption("Prehodi v informacionniq potok, zasqgashi modificiraneto na programniq broq4", 1);
    exam.push_back(u15);

    Question u16("Na kakvo se duljat precedurnite zavisimosti");
    u16.AddOption("Edinstveno na instrukcii za bezusloven prehod", 0);
    u16.AddOption("Edinstveno na instrukcii za usloven prehod ", 0);
    u16.AddOption("Instrukcii za bezusloven prehod i instrukcii s osushtestven usloven prehod v instrukcionniq potok na programata", 1);
    u16.AddOption("Ednovremenniqt .... za edin i susht resurs", 0);
    exam.push_back(u16);

    Question u17("Ot kakvo predizvikvat resursnite konflikti?");
    u17.AddOption("Ne dobro planirane na resursite na instrukcionniq konveyer", 0);
    u17.AddOption("Ednovremenni zaqvki za edni i susti resursi", 1);
    u17.AddOption("Ot vuzniknali mehuri v konveyera", 0);
    exam.push_back(u17);

    Question u18("Koi ot izbroenite metodi se izpolzva za reshavane na problema s instrukcionnite hazarti ? (izberete edno ili pove4e)");
    u18.AddOption("Prezarejdane na konveyera ", 0);
    u18.AddOption("Uveli4avane razmera na bufernata pamet v otdelnite funkcionalni ustroistva", 0);
    u18.AddOption("Oprostqvane formata na instrukciite izpolzvani ot programata", 0);
    u18.AddOption("Razdelqne na instrukcionniq cikul na dopulnitelni fazi na obrabotka", 0);
    u18.AddOption("Prenarejdane na instrukcii ot kompilatora", 1);
    exam.push_back(u18);

    //random
    Question q14("Superskalaren procesor obrabotva dva instrukcionni potoka(ot prosti i slojni instrukcii)Koq ot izbroenite fazi na razrabotka e obshta i za dvata potoka?");
    q14.AddOption("Izvlichane", 1);
    q14.AddOption("Izpalnenie", -1);
    q14.AddOption("Zapis na rezultata", -1);
    q14.AddOption("Dekodirane", -1);
    exam.push_back(q14);

    Question q15("Kakvo e prednaznachenieto na mehanizmite za zashtita na pametta?");
    q15.AddOption("Da ne dopuskat modificirane na sistemniq softuer ot prilojeniq", -1);
    q15.AddOption("Da ogranichavat dostupa do suhranqvanata v sistemata informaciq", -1);
    q15.AddOption("Da otkrivat greshki pri adresiraneto predi izvurshvaneto na nerazreshen dostup", -1);
    q15.AddOption("Da organizirat dostupa do opredeleni segmenti ili stranici", 1);
    exam.push_back(q15);

    Question q16("Shinata PCI v procesornata arhitektura se qvqva most mejdu:");
    q16.AddOption("shina EISA i periferiqta", 1);
    q16.AddOption("sistemnata shina na mikroprocesora i shinata EISA", -1);
    q16.AddOption("sistemnata shina na mikroprocesora i osnovnata pamet", -1);
    q16.AddOption("mikroprocesora i kesh pametta L2", -1);
    exam.push_back(q16);

    Question q17("Koq/koi ot izbroenite shini ne sa chast ot sistemnata shina?");
    q17.AddOption("Shina za danni", -1);
    q17.AddOption("Shina za logicheski signali", 1);
    q17.AddOption("Kontrolna shina", -1);
    q17.AddOption("Adresna shina", -1);
    exam.push_back(q17);

    Question q18("V rejim na direkten dostap do pametta, upravlenieto na obmena se poema ot:");
    q18.AddOption("Ustroystvoto za vhod/izhod", 1);
    q18.AddOption("Procesora", -1);
    q18.AddOption("Glavnata pamet", -1);
    exam.push_back(q18);

    //ISA
    Question q19("V zavisimost ot rejima na adresaciq vremeto za izpalnenie na edna procesorna instrukciq moje da varira v znachitelna stepen. Pri koq ot izbroenite podredbi na adresni rejimi vremeto shte se izmenq ot mnogo kratko do mnogo dulgo?");
    q19.AddOption("prqka, kosvena, neposredstvena", -1);
    q19.AddOption("neposredstvena, kosvena, prqka", -1);
    q19.AddOption("neposredstvena, prqka, kosvena", 1);
    q19.AddOption("kosvena, neposredstvena, prqka", -1);
    exam.push_back(q19);

    Question q20("Koy ot izbroenite etapi ne e chast ot instrukcionniq cikal?");
    q20.AddOption("Prenarejdane", 1);
    q20.AddOption("Izvlichane", -1);
    q20.AddOption("Izpalnenie", -1);
    q20.AddOption("Dekodirane", -1);
    exam.push_back(q20);

    Question q21("koi procesori ot izbroenite procesorni familii se harakterizirat s RISC-arhitektura?");
    q21.AddOption("SPARC", 1);
    q21.AddOption("CYRIX", -1);
    q21.AddOption("ALPHA", -1);
    q21.AddOption("INTEL", -1);
    q21.AddOption("AMD", -1);
    q21.AddOption("MIPS-R4000", 1);
    q21.AddOption("ARM", 1);
    exam.push_back(q21);

    Question q22("Kakva sistema instrukcii imat razlichnite familii multiprocesorni arhitekturi?");
    q22.AddOption("Ednakva", -1);
    q22.AddOption("Suvpadashta otchasti", 0.5);
    q22.AddOption("Izcqlo razlichna", 0.5);
    exam.push_back(q22);

    Question q23("Koy ot izbroenite etapi e chast ot instrukcionniq cikal?");
    q23.AddOption("Prenarejdane", -1);
    q23.AddOption("Izvlichane", 0.34);
    q23.AddOption("Izpalnenie", 0.33);
    q23.AddOption("Dekodirane", 0.33);
    exam.push_back(q23);


    //komp arch
	Question u1("Ot koi faktori zavisi proizvoditelnostta na komputurnite sistemi?");
	u1.AddOption("Ot vremeto za dostup do registrirane", 0);
	u1.AddOption("Arhitekturata i tehnologiqta", 1);
	u1.AddOption("Ot taktovata 4estota", 0);
    exam.push_back(u1);

	Question u2("Edinicata za izmervane na proizvoditelnostta MIPS za supostavqne na ednotipni procesorni arhitekturi se osnovava na:");
	u2.AddOption("Broi operacii s operandi ot virtualnata pamet", 0);
	u2.AddOption("Broi operacii s operandi ot kesh pametta", 0);
	u2.AddOption("Broi operacii s operandi ot glavnata pamet", 1);
	u2.AddOption("Broi operacii s operandi ot flash-pametta", 0);
    exam.push_back(u2);

	Question u3("Osnovni proizvoditeli na x86 arhitekturata sa:(Izberete edno ili poveche)");
	u3.AddOption("IBM", 1);
	u3.AddOption("Hewlett-Packard", 1);
	u3.AddOption("Intel", 1);
	u3.AddOption("Sun Microsystems", 0);
	u3.AddOption("Advanced Micro Device", 0);
    exam.push_back(u3);

	Question u4("Za kakvo sluji programniqt broq4 (Izberete edno)");
	u4.AddOption("Za ukazvane adresa na sledvashtata instrukciq za izpylnenie", 1);
	u4.AddOption("Za suhranqvane na rezultata ot aritmetichnite operacii izpulnqvani v ALU-to", 0);
	u4.AddOption("Za ot4itane broq na izpulneniqta na dadena instrukciq ", 0);
	u4.AddOption("Za ot4itane na procenta pamet zaeman ot izpulnqvashtata se programa", 0);
    exam.push_back(u4);

	Question u5("Koq e pravilnata definiciq za termina SIMD> (Izberete edno)");
	u5.AddOption("Single Instruction, Multiple Data", 1);
	u5.AddOption("Single interrupt, Multiple Distribution", 0);
	u5.AddOption("Single input, Multiple Distributions", 0);
	u5.AddOption("Single integration, Multiple Dynamics", 0);
    exam.push_back(u5);

	Question u6("Koi ot izbroenite tehniki slujat za uveli4avane stepenta na paralelizum po vreme na izpulnenie na programata (izberete edno ili pove4e)");
	u6.AddOption("nito edno ot poso4enite ", 0);
	u6.AddOption("Prognozirane posokata na prehodite", 0.25);
	u6.AddOption("Ednovremenno zarejdane za izpulnenie na nqkolko instrukcii i dinami4no planirane", 0.25);
	u6.AddOption("Otkrivane i premahvane na zavisimosti po danni pri kompilirane", 0.25);
	u6.AddOption("Reorganizaciq na ciklite po takuv na4in, 4e wsqka iteraciq w polu4eniq kod da se sustoi ot instrukcii, koito sa izbrani ot razli4ni iteracii na purvona4alniq cikul(loop unrolling)", 0.25);
    exam.push_back(u6);

    for(unsigned i =0; i<exam.size(); ++i)
        std::swap(exam[Randomize(exam.size())],exam[Randomize(exam.size())]);

    char useless;
    for(unsigned i =0; i<exam.size(); ++i)
    {
        exam[i].AskQuestion();
        exam[i].AnswerQuestion();
        std::cin>>useless;
    }
    return 0;
}
