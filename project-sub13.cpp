#include "project-sub13.hpp"
//------------
int logged_user_index; //انديس كاربر در منوي لاگين
APP App;
char emoji(int x)
{
    string emoji = "~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL: ZXCVBNM<>?*`1234567890-=qwertyuiop[]\asdfghjkl;'zxcvbnm,./";
    for (int i = 0; emoji[i] != '\0'; i++)
        emoji[i] -= '0';
    return emoji[x];
}
//----------------------------------------------
int get_command_code() //دريافت كد از كاربر
{
    string command_code;
    int code;
    while (true)
    {
        cout << ">> Enter your command code: "; //enter the command code to begin
        getline(cin, command_code);
        if (command_code.length() == 0)
            command_code = "#error";
        if (count_condition_in_str(command_code, '0', '9') == command_code.length())
        {
            code = stoi(command_code);
            break;
        }
        else
        {
            cout << "\n"
                 << "\t"
                 << " use the number for input OK!"
                 << "\n"
                 << "\n";
        }
    }
    return code;
}
//------------------------------------------
void print_main_menu()
{
    cout << "\n " << emoji(50) << " Click Enter...";
    cin.get();
    system("cls");
    cout << "\n"
         << "1. SingUp"
         << "\n"
         << "2. login"
         << "\n"
         << "3. Exit "
         << "\n";
}
//------------
void main_menu()
{
    while (true)
    {
        print_main_menu();
        switch (get_command_code())
        {
        case 1: //1. SingUp
            singup();
            break;
        case 2: //2. Login
            login_entery();
            break;
        case 3: //3. Exit
            cout << "\n"
                 << "\t"
                 << " exit succssfully done " << emoji(50)
                 << "\n";
            exit(0);
        default:
            cout << "\n"
                 << "\t"
                 << " please choose the number from the menu "
                 << "\n";
        }
    }
}
//-------------
void singup()
{
    cout << "\n"
         << "welcome to singup " << emoji(49)
         << "\n"; // پيام ورودي به ثبت نام
    int singup_user_index = App.Users_num;
    //--------------------------شروع ثبت نام

    get_first_name(singup_user_index);        // دریافت اسم کاربر
    get_last_name(singup_user_index);         // دریافت فاميل کاربر
    get_phone_number(singup_user_index);      // دریافت شماره تلفن کاربر
    get_username(singup_user_index);          // دریافت يوزرنيم کاربر
    get_password(singup_user_index);          // دریافت پسورد کاربر
    get_password_confiorm(singup_user_index); // دريافت تاييدكننده ي پسورد كاربر

    //--------------------------پایان ثبت نام
    cout << "\n"
         << "\t"
         << App.USER[singup_user_index].first_name
         << " singup succssfully done " << emoji(50)
         << "\n";
    App.USER[singup_user_index].user_id += App.Users_num;
    App.Users_num++; //اضافه شدن كاربر جديد
    main_menu();
}
//----
void get_first_name(int user_index) //اسم را از كاربر گرفته و ذخيره مي كند
{
    string Current_FirstName; //اسمي كه درتابع از كاربر ميگيرد
    while (true)
    {
        cout << ">> Dear friend please enter your first name: ";
     getline(cin, Current_FirstName);//
        if (check_name(Current_FirstName))
        {
            App.USER[user_index].first_name = Current_FirstName; //ذخيره ي اسم ورودي
            break;
        }
        else
        {
            if (!interest_of_continue("\n\t sorry wrong input  :( \n >> Do you want to repeat it ?"))
            {
                cout << "\n"
                     << "\t"
                     << " task failed :( "
                     << "\n";
                main_menu();
                break; //كاربر تمايل به ادامه ندارد
            }
        }
    }
}
//---------------------------------
void get_last_name(int user_index) //فاميل را از كاربر گرفته و درستي را بازميگرداند و در ارايه ي خود ذخيره مي كند
{
    string Current_LastName; //فاميلي اي  كه در تابع از كاربر ميگيرد
    while (true)
    {
        cout << ">> Dear "
             << App.USER[user_index].first_name
             << " please enter your last name: ";
        getline(cin, Current_LastName);
        if (check_name(Current_LastName))
        {
            App.USER[user_index].last_name = Current_LastName; //ذخيره ي فاميل ورودي
            break;
        }
        else
        {
            if (!interest_of_continue("\n\t sorry wrong input  :( \n >> Do you want to repeat it ?"))
            {
                cout << "\n"
                     << "\t"
                     << " task failed :( "
                     << "\n";
                main_menu();
                break; //كاربر تمايل به ادامه ندارد
            }
        }
    }
}
//---------------------------------
void get_phone_number(int user_index) //شماره تلفن  را از كاربر گرفته و درستي را بازميگرداند و در ارايه ي خود ذخيره مي كند
{
    string Current_PhoneNumber;
    while (true)
    {
        cout << ">> Dear "
             << App.USER[user_index].first_name
             << " please enter your phone number: ";
   getline(cin, Current_PhoneNumber);
        if (check_phone_number(Current_PhoneNumber))
        {
            App.USER[user_index].phone_number = Current_PhoneNumber;
            break;
        }
        else
        {
            if (!interest_of_continue("\n\t sorry wrong input  :( \n >> Do you want to repeat it ?"))
            {
                cout << "\n"
                     << "\t"
                     << " task failed :( "
                     << "\n";
                main_menu();
                break; //كاربر تمايل به ادامه ندارد
            }
        }
    }
}
//---------------------------------
void get_username(int user_index) //يوزرنيم را از كاربر گرفته و درستي را بازميگرداند و در ارايه ي خود ذخيره مي كند
{
    string Current_usernNamr; //يوزرنيم كه درتابع از كاربر ميگيرد
    while (true)
    {
        cout << ">> Dear "
             << App.USER[user_index].first_name
             << " please enter your username: ";
     getline(cin, Current_usernNamr);
        if (check_username(Current_usernNamr))
        {
            App.USER[user_index].username = Current_usernNamr; //ذخيره ي يوزرنيم ورودي
            break;
        }
        else
        {
            if (!interest_of_continue("\n\t sorry wrong input  :( \n >> Do you want to repeat it ?"))
            {
                cout << "\n"
                     << "\t"
                     << " task failed :( "
                     << "\n";
                main_menu();
                break; //كاربر تمايل به ادامه ندارد
            }
        }
    }
}
//---------------------------------
void get_password(int user_index) //پسورد را از كاربر گرفته و درستي را بازميگرداند و در ارايه ي خود ذخيره مي كند
{
    string Current_PassWord; //پسورد كه درتابع از كاربر ميگيرد
    while (true)
    {
        cout << ">> Dear "
             << App.USER[user_index].first_name
             << " please enter your password: ";
       getline(cin, Current_PassWord);
        if (check_password(Current_PassWord))
        {
            App.USER[user_index].password = Current_PassWord; //ذخيره ي پسورد ورودي براي تاييد گرفتن
            break;
        }
        else
        {
            if (!interest_of_continue("\n\t sorry wrong input  :( \n >> Do you want to repeat it ?"))
            {
                cout << "\n"
                     << "\t"
                     << " task failed :( "
                     << "\n";
                main_menu();
                break; //كاربر تمايل به ادامه ندارد
            }
        }
    }
}
//---------------------------------
void get_password_confiorm(int user_index) //دريافت پسورد تاييدكنننده كاربر
{
    string Current_PassWordConfiorm; //پسورد كه درتابع از كاربر ميگيرد
    while (true)
    {
        cout << ">> Dear "
             << App.USER[user_index].first_name
             << " please enter your password again to confiotm your password: ";
    getline(cin, Current_PassWordConfiorm);
        if (check_two_string(Current_PassWordConfiorm, App.USER[user_index].password))
            break;

        else
        {
            cout << "\t"
                 << "the confiorm password that you entered dosen't match the password  "
                 << "\n";
            if (!interest_of_continue("\n\t  >> Do you want to repeat it ?"))
            {
                cout << "\n"
                     << "\t"
                     << " task failed :( "
                     << "\n";
                main_menu();
                break; //كاربر تمايل به ادامه ندارد
            }
        }
    }
}
//---------------------------------

//--------------------------------
bool check_name(string input)
{
    if (!(input.length() <= lenmaxName))
        cout << "\t"
             << "the lenght of your input must be less then "
             << lenmaxName
             << "\n";
    if (!(input.length() >= lenmin))
        cout << "\t"
             << "the lenght of your input must be more then "
             << lenmin
             << "\n";
    if (!(count_condition_in_str(input, '0', '9') == 0))
        cout << "\t"
             << "the input should not have number in it "
             << "\n";
    return (input.length() <= lenmaxName) &&
           (input.length() >= lenmin) &&
           (count_condition_in_str(input, '0', '9') == 0);
}
//---------------------------------
bool check_phone_number(string input)
{
    if (found_phonenumber(input) != -1)
        cout << "\t"
             << "this username already token "
             << "\n";
    if (!(input.length() == lenmaxPhoneNumber))
        cout << "\t"
             << "the lenght of your input must be  "
             << lenmaxPhoneNumber
             << "\n";
    if (!(count_condition_in_str(input, '0', '9') == lenmaxPhoneNumber))
        cout << "\t"
             << "the input should be all number "
             << "\n";
    if (!(input[0] == '0' && input[1] == '9'))
        cout << "\t"
             << "the input start with 09 like 09xxxxxxxxx "
             << "\n";
    return (input.length() == lenmaxPhoneNumber) &&
           (count_condition_in_str(input, '0', '9') == lenmaxPhoneNumber) &&
           (found_phonenumber(input) == -1 &&
            (input[0] == '0' && input[1] == '9'));
}
//---------------------------------
bool check_username(string input)
{
    if (found_username(input) != -1)
        cout << "\t"
             << "this username already token "
             << "\n";
    if (!(input.length() == lenmaxUsername))
        cout << "\t"
             << "the lenght of your input must be  "
             << lenmaxUsername
             << "\n";
    if (!(input[0] == '9' &&
          (input[input.length() - 1] == '3' || input[input.length() - 1] == '5')))
        cout << "\t"
             << "the input should start with 9 and end with 3 or 5 "
             << "\n";
    return (input.length() == lenmaxUsername) &&
           (!(found_username(input) != -1)) &&
           (input[0] == '9' &&
            (input[input.length() - 1] == '3' || input[input.length() - 1] == '5'));
}
//---------------------------------
bool check_password(string input)
{
    if (!(input.length() <= lenmaxPassword))
        cout << "\t"
             << "the lenght of your input must be less than "
             << lenmaxPassword
             << "\n";
    if (!(input.length() >= lenminPassword))
        cout << "\t"
             << "the lenght of your input must be more than "
             << lenminPassword
             << "\n";
    if (!(have_condition_in_str(input, 'A', 'Z')))
        cout << "\t"
             << "the input should at least have one big latter  "
             << "\n";
    if (!(have_condition_in_str(input, 'a', 'z')))
        cout << "\t"
             << "the input should at least have one small latter  "
             << "\n";
    if (!(have_condition_in_str(input, '0', '9')))
        cout << "\t"
             << "the input should at least have one number  "
             << "\n";
    return (input.length() <= lenmaxPassword) &&
           (input.length() >= lenminPassword) &&
           (have_condition_in_str(input, 'A', 'Z')) &&
           (have_condition_in_str(input, 'a', 'z')) &&
           (have_condition_in_str(input, '0', '9')); //حداقل پسورد يك حرف بزرگ و كوچك انگليسي و يك عددو حداقل و حداكثر رو رعايت كند
}
//---------------------------------
bool check_two_string(string input1, string input2)
{
    if (input1.compare(input2) == 0)
    {
        return true;
    }
    return false;
}
//---------------------------------
int found_phonenumber(string Current_phonenumber)
{
    for (int index = 0; index < App.Users_num; index++) //index شماره كاربران در ليست
    {
        if (App.USER[index].phone_number.compare(Current_phonenumber) == 0)
            return index; //قبلا وجود داشته است
    }
    return -1;
}
//---------------------------------
int found_username(string Current_username)
{
    for (int index = 0; index < App.Users_num; index++) //index شماره كاربران در ليست
    {
        if (App.USER[index].username.compare(Current_username) == 0)
            return index; //قبلا وجود داشته است
    }
    return -1;
}
//---------------------------------
bool interest_of_continue(string massage) //متن سوال ورودي//جواب سوال ایا ادامه میدهید؟
{
    string answer;
    while (true)
    {
        cout << massage
             << " Y/N : ";
        getline(cin, answer);
        if (answer.length() != 1)
            answer = '#';
        switch (answer[0])
        {
        case 'y':
        case 'Y':
            return true;
        case 'n':
        case 'N':
            break;
        case '#':
        default:
            cout << "\n"
                 << "\t"
                 << "please use 'y' OR 'Y' for YES and 'N' OR 'n' for NO "
                 << "\n";
            continue;
        }
        break;
    }
    return false; //كاربر تمايلي به ادامه ندارد
}
//-------------------------------
int count_condition_in_str(string input, char start, char end) //شمارش تعداد خانه هايي از رشته كه شرط بين "شروع "و""پايان" را دارند
{
    int num = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= start && input[i] <= end)
            num++;
    }
    return num;
}
//-------------------------------
bool have_condition_in_str(string input, char start, char end) //شمارش تعداد خانه هايي از رشته كه شرط بين "شروع "و""پايان" را دارند
{
    int num = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= start && input[i] <= end)
            return true;
    }
    return false;
}
//--------------------------------------------------

//project_number=App.USER[logged_user_index].project_num;
#define project_number App.USER[logged_user_index].project_num

//project_number=App.USER[logged_user_index].project_num;
//project_=App.USER[logged_user_index].Project[project_number]
#define project_ App.USER[logged_user_index].Project[project_number]
//-------------
void login_entery() //عمليات ورود
{
    cout << "\n"
         << "welcome to login " << emoji(49)
         << "\n";                                          // پيام ورودي به ورود
    cout << ">>Dear friend please enter your username : "; //دريافت يوزرنيم
    string username;
    getline(cin, username);
    int username_Index = found_username(username);
    if (username_Index == -1)
    {
        cout << "\n"
             << "\t"
             << "Oops you enter the wrong username OR forgot to singup ;("
             << "\n";
        return; // يا اشتباه وارد كرده//كاربر قبلا ثبت نام نكرده است//
    }
    logged_user_index = username_Index; //int username_Index=found_username(username);
    while (true)
    {
        cout
            << ">>Dear "
            << App.USER[logged_user_index].first_name
            << " please enter your password : ";
        string login_password;
         getline(cin, login_password);
        if (check_two_string(login_password, App.USER[logged_user_index].password) == false)
        {
            if (!interest_of_continue("\n\t Oh the password is not correct  :( \n >> Do you want to repeat it ? "))
                return; ////كاربر تمايل به ادامه ندارد
        }
        else
            break;
    }
    cout << "\n"
         << "\t"
         << App.USER[logged_user_index].first_name
         << " login succssfully done " << emoji(50)
         << "\n";
    //-------كاربر وارد برنامه شده و برنامه شماره كاربر را ميداند
     
    login_first_menu();
}
//-------------------------------
void print_login_first_menu()
{
    cout << "\n " << emoji(50) << " Click Enter...";
    cin.get();
    system("cls");
    ///
    cout << "\n"
         << "1. Create a new project"
         << "\n"
         << "2. Create a new task"
         << "\n"
         << "3. settings"
         << "\n"
         << "4. See Reports"
         << "\n"
         << "5. Logout"
         << "\n"
         << "6. Exit "
         << "\n";
}
//-------------------------------
void login_first_menu()
{
    while (true)
    {
        print_login_first_menu();
        int command_code = get_command_code();
        //-----
        switch (command_code)
        {
        case 5: //Exit
            main_menu();
            break;
        case 6:
            cout << "\n"
                 << "\t"
                 << " exit succssfully done " << emoji(50)
                 << "\n";
            exit(0);
        default:
            break;
        }
        //-----
        if (project_number < min_user_project) //اگر پروژه اي نداره بهش بگه
        {
            cout << "\n"
                 << "\t"
                 << " Dear "
                 << App.USER[logged_user_index].first_name
                 << " you dont have any project yet! try make one now  " << emoji(50) << " "
                 << "\n";
            command_code = 1;
        }
        switch (command_code)
        {
        case 1:
            Create_new_project(logged_user_index);
            break;
        case 2:
        {
            int current_project_num = found_project_index(logged_user_index); //  انديس پروژه
            if (current_project_num == -1)                                    // در صورت موجود نبودن -1
                continue;
            Create_task(logged_user_index, current_project_num);
        }
        break;
        case 3:
            info_settings(logged_user_index);
            break;
        case 4:
            Report_info(logged_user_index);
            break;
        default:
            cout << "\n"
                 << "\t"
                 << " please choose the number from the menu "
                 << "\n";
        }
    }
}
//-------------------------------
void Create_new_project(int user_index)
{
#define current_project_number App.USER[user_index].project_num
#define current_project_ App.USER[user_index].Project[current_project_number]
    if (current_project_number == max_user_project) //اگر پروژه ها به ماكيسمم رسيد خارج شود
    {
        cout << "\n"
             << "\t"
             << " Dear "
             << App.USER[user_index].first_name
             << " you reach the max limit on project number !"
             << "\n";
        login_first_menu();
        return;
    }
    //شروع دريافت اطلاعات اين قسمت
    //هر قسمت اگر با موفقيت به اتمام رسيده نباشد خطا داد و به منوي قبل باز ميگردد
    cout << endl;
    int create_project_index = current_project_number;

    get_project_name(user_index, create_project_index);
    get_project_members_num(user_index, create_project_index);
    get_project_leader_name(user_index, create_project_index);
    get_project_salary(user_index, create_project_index);
    current_project_.project_id += current_project_number;

    current_project_.all_task_duration.zero(); //صفر كردن طول زمان پروژ
    current_project_number++;
    cout << "\n"
         << "\t"
         << ">> well done "
         << App.USER[user_index].first_name
         << " you create your "
         << convertinteger2digit(App.USER[user_index].project_num) //اسم عدد
         << "project  " << emoji(50) << " "
         << "\n";
#undef current_project_number
#undef current_project_
}
//-------------------------------
void get_project_name(int user_index, int project_i)
{
    string current_project_name; //اسم پروژه ي فعلي
    while (true)
    {
        cout << ">> Dear "
             << App.USER[user_index].first_name
             << " please enter your project name : ";
        getline(cin, current_project_name);
        if (current_project_name.length() < 1) // اگر خالي وارد كرد بود
            if (!interest_of_continue("\n\t sorry input cant be less than 1 !  \n >> Do you want to try again it ?"))
            {
                cout << "\n"
                     << "\t"
                     << "ok ! "
                     << "\n";
                login_first_menu();
                break; //كاربر تمايل به ادامه ندارد
            }
            else
                continue;
        if (check_project_name(user_index, current_project_name))
        {
            App.USER[user_index]
                .Project[App.USER[user_index].project_num]
                .project_name = current_project_name;
            break;
        }
        else
        {
            if (!interest_of_continue("\n\t sorry worng input !  \n >> Do you want to try again it ?"))
            {
                cout << "\n"
                     << "\t"
                     << "ok ! "
                     << "\n";
                login_first_menu();
                break; //كاربر تمايل به ادامه ندارد
            }
        }
    }
}
//-------------------------------
bool check_project_name(int user_index, string current_project_name) //بررسي اسم پروژه ي كاربر
{
    if (current_project_name.compare("all") == 0)
    {
        cout << "\n input cant be 'all' \n";
        return false;
    }
    for (int index = 0; index < App.USER[user_index].project_num; index++)
    {
        if (App.USER[user_index].Project[index].project_name.compare(current_project_name) == 0) //اگر قبلا يه مشابهي داشت
        {
            cout << "\n this already token !\n";
            return false;
        } //قبلا وجود داشته پس اين اسم قابل استفاده نيست
    }
    return true;
}
//-------------------------------
void get_project_members_num(int user_index, int project_i)
{
    string receved_num;
    while (true)
    {
        cout << ">> Dear "
             << App.USER[user_index].first_name
             << " please enter the project number of team members : ";

        getline(cin, receved_num);
        if (receved_num.compare("0") == 0)
            if (!interest_of_continue("\n\t sorry the number of team can't be zero !  \n >> Do you want to try again it ?"))
            {
                cout << "\n"
                     << "\t"
                     << "ok ! "
                     << "\n";
                login_first_menu();
                break; //كاربر تمايل به ادامه ندارد
            }
            else
                continue;
        if (receved_num.length() < 1)
            if (!interest_of_continue("\n\t sorry wrong input !  \n >> Do you want to try again it ?"))
                return;
            else
                continue;
        if (count_condition_in_str(receved_num, '0', '9') == receved_num.length())
        {
            App.USER[user_index]
                .Project[project_i]
                .num_of_project_members = stoi(receved_num);
            break;
        }
        else
        {
            if (!interest_of_continue("\n\tthe number of team members can't be that \n >> Do you want to try again it ?"))
            {
                cout << "\n"
                     << "\t"
                     << "ok ! "
                     << "\n";
                login_first_menu();
                break; //كاربر تمايل به ادامه ندارد
            }
        }
    }
}
//-------------------------------
void get_project_leader_name(int user_index, int project_i)
{
    string current_project_leader_name; //اسم پروژه ي فعلي
    while (true)
    {
        cout << ">> Dear "
             << App.USER[user_index].first_name
             << " please enter your name of project leader : ";
        getline(cin, current_project_leader_name);
        if (current_project_leader_name.length() < 1) // اگر خالي وارد كرد بود
            if (!interest_of_continue("\n\t sorry wrong input !  \n >> Do you want to try again it ?"))
            {
                cout << "\n"
                     << "\t"
                     << "ok ! "
                     << "\n";
                login_first_menu();
                break; //كاربر تمايل به ادامه ندارد
            }
            else
                continue;
        if (count_condition_in_str(current_project_leader_name, '0', '9') == 0)
        {
            App.USER[user_index]
                .Project[project_i]
                .project_leader_name = current_project_leader_name;
            break;
        }
        else
        {
            if (!interest_of_continue("\n\t sorry this name couldn't have number in it  !  \n >> Do you want to try again it ?"))
            {
                cout << "\n"
                     << "\t"
                     << "ok ! "
                     << "\n";
                login_first_menu();
                break; //كاربر تمايل به ادامه ندارد
            }
        }
    }
}
//-------------------------------
void get_project_salary(int user_index, int project_i)
{
    string receved_num;
    while (true)
    {
        cout << ">> Dear "
             << App.USER[user_index].first_name
             << " please enter the salary project (Doller per hour) EX-> 20.50 OR 15  : ";

        getline(cin, receved_num);
        if (receved_num.length() < 1)
            if (interest_of_continue("\n\t sorry wrong input !  \n >> Do you want to try again it ?"))
            {
                cout << "\n"
                     << "\t"
                     << "ok ! "
                     << "\n";
                login_first_menu();
                break; //كاربر تمايل به ادامه ندارد
            }
            else
                continue;
        if ((count_condition_in_str(receved_num, '0', '9') == (receved_num.length() - 1) &&
             count_condition_in_str(receved_num, '.', '.') == 1) ||
            count_condition_in_str(receved_num, '0', '9') == receved_num.length())
        {
            App.USER[user_index]
                .Project[project_i]
                .project_salary = stof(receved_num);
            break;
        }
        else
        {
            if (!interest_of_continue("\n\t sorry wrong input  :( \n >> Do you want to try again it ?"))
            {
                cout << "\n"
                     << "\t"
                     << "ok ! "
                     << "\n";
                login_first_menu();
                break; //كاربر تمايل به ادامه ندارد
            }
        }
    }
}
//-------------------------------
int found_project_index(int user_index)
{
    while (true)
    {
        print_project_names(user_index);
        cout << endl; //اگر پروژه اي داشت اسم يا عددش را بگيره و ادامه بده
        cout << ">> Dear "
             << App.USER[user_index].first_name
             << " please enter the name or number of the chosen project :";
        string project_str;
        getline(cin, project_str);
        if (project_str.compare("all") == 0)
            return -2;
        if (project_str.length() < 1)
        {
            cout << " \n input can't be empty\n";
            continue;
        }
        if (count_condition_in_str(project_str, '0', '9') == project_str.length()) //جواب عدد باشد
        {
            int project_index;
            project_index = stoi(project_str);
            if (project_index >= min_user_project &&
                project_index <= App.USER[user_index].project_num)
            {
                return (project_index - 1); //چون منو از يك شروع شده
            }
        }
        else //جواب رشته است
        {
            for (int index = 0; index < App.USER[user_index].project_num; index++)
            {
                if (App.USER[user_index].Project[index].project_name.compare(project_str) == 0)
                    return index;
            }
        }
        //پيدا نشده
        if (interest_of_continue("\n\t sorry I couldn't find the input that you entred :( \n\t make sure its carrect! \n >> Do you want to repeat it ? "))
            continue;
        else
            break;
    }
    //کلا نباشد
    return -1;
}
//-------------------------------
void print_project_names(int user_index)
{
    for (int index = 0; index < App.USER[user_index].project_num; index++)
    {
        cout << "\t"
             << index + 1
             << "-"
             << App.USER[user_index].Project[index].project_name;
        if ((index + 1) % 3 == 0)
        {
            cout << endl; //هر سه كلمه اي برود خط بعد
        }
    }
}
//-------------------------------
int found_task_index(int user_index, int project_index)
{
    while (true)
    {
        print_task_names(user_index, project_index);
        cout << endl; //اگر پروژه اي داشت اسم يا عددش را بگيره و ادامه بده
        cout << ">> Dear "
             << App.USER[user_index].first_name
             << " please enter the name or number of the chosen task :";
        string task_str;
        getline(cin, task_str);
        if (task_str.compare("all") == 0)
            return -2;
        if (task_str.length() < 1)
        {
            cout << " \n input can't be empty \n";
            continue;
        }
        if (count_condition_in_str(task_str, '0', '9') == task_str.length()) //جواب عدد باشد
        {
            int task_index;
            task_index = stoi(task_str);
            if (task_index >= 1 &&
                task_index <= App.USER[user_index].Project[project_index].task_num)
            {
                return (task_index - 1); //چون منو از يك شروع شده
            }
        }
        else //جواب رشته است
        {
            for (int index = 0; index < App.USER[user_index].Project[project_index].task_num; index++)
            {
                if (App.USER[user_index].Project[index].project_name.compare(task_str) == 0)
                    return index;
            }
        }
        //پيدا نشده
        if (interest_of_continue("\n\t sorry I couldn't find the input that you entred :( \n\t make sure its carrect! \n >> Do you want to repeat it ? "))
            continue;
        else
            break;
    }
    //کلا نباشد
    return -1;
}
//-------------------------------
void print_task_names(int user_index, int project_index)
{
    for (int index = 0; index < App.USER[user_index].Project[project_index].task_num; index++)
    {
        cout << "\t"
             << index + 1
             << "-"
             << App.USER[user_index].Project[project_index].task[index].task_name;
        if ((index + 1) % 3 == 0)
        {
            cout << endl; //هر سه كلمه اي برود خط بعد
        }
    }
}
//-------------------------------
void Create_task(int user_index, int current_project_num)
{
#define current_project_ App.USER[user_index].Project[current_project_num]
#define current_project_task current_project_.task[current_project_.task_num]
    while (true)
    { //---گرفتن اسم تسك
        cout
            << "\n"
            << " >> Dear "
            << App.USER[user_index].first_name
            << " please enter the task name : ";

        getline(cin, current_project_task.task_name);
        if (current_project_task.task_name.compare("all") == 0)
            if (!interest_of_continue("\n\t input cant be 'all' \n\t >> Do you want to try again it ?"))
            {
                cout << "\n"
                     << "\t"
                     << "ok ! "
                     << "\n";
                login_first_menu();
                return;
            }
            else
                continue;
        else
            break;
    }
    //-----زمان شروع تسك
    string temp_;
    cout << "\n"
         << "Well  " << emoji(50) << " Click enter to get started : ";
    getline(cin, temp_);
    auto start = chrono::high_resolution_clock::now();
    //----زمان پايان تسك
    current_project_task.task_start_point = chrono::high_resolution_clock ::to_time_t(start);
    cout << "\n"
         << "\t"
         << ">>  the task "
         << current_project_task.task_name
         << " started in "
         << ctime(&current_project_task.task_start_point)
         << "\n"
         << "When its done ,  " << emoji(50) << " Click enter to finish : ";
    getline(cin, temp_);
    auto end = chrono::high_resolution_clock::now();
    current_project_task.task_end_point = chrono::high_resolution_clock ::to_time_t(end);
    //----
    current_project_task.task_duration = end - start;
    current_project_.all_task_duration += current_project_task.task_duration;
    //----
    cout << "\n"
         << "\t"
         << ">>  the task "
         << current_project_task.task_name
         << " finished in "
         << ctime(&current_project_task.task_end_point);
    current_project_task.task_id += current_project_.task_num;
    current_project_.task_num++;
#undef current_project_task
#undef current_project_
}
//-------------------------------
void print_info_settings_menu()
{
    cout << "\n " << emoji(50) << " Click Enter...";
    cin.get();
    system("cls");
    cout << " 1. projects settings "
         << "\n"
         << " 2. user settings "
         << "\n"
         << " 3. Go back"
         << "\n"
         << " 4. Logout"
         << "\n";
}
//-------------------------------
void info_settings(int user_index)
{
    while (true)
    {
        print_info_settings_menu();
        switch (get_command_code())
        {
        case 1:
            Project_settings(user_index);
            break;
        case 2:
            user_settings(user_index);
            break;
        case 3:
            login_first_menu();
            break;
        case 4:
            main_menu();
            break;
        default:
            cout << "\n"
                 << "\t"
                 << " please choose the number from the menu "
                 << "\n";
        }
    }
}
//-------------------------------
void print_project_settings_menu()
{
    cout << "\n " << emoji(50) << " Click Enter...";
    cin.get();
    system("cls");
    cout << "\n"
         << "1. Change the amount of project members"
         << "\n"
         << "2. Change the name of project leader"
         << "\n"
         << "3. Increase the salary of project"
         << "\n"
         << "4. Delete a project"
         << "\n"
         << "5. Go back"
         << "\n"
         << "6. Logout"
         << "\n";
}
//-------------------------------
void Project_settings(int user_index)
{
    while (true)
    {
        print_project_settings_menu();
        switch (get_command_code())
        {
        case 1:
            Change_num_project_member(user_index);
            break;
        case 2:
            Change_name_project_leader(user_index);
            break;
        case 3:
            increase_project_salary(user_index);
            break;
        case 4:
            delete_project(user_index);
            break;
        case 5:
            info_settings(user_index);
            break;
        case 6:
            main_menu();
            break;
        default:
            cout << "\n"
                 << "\t"
                 << " please choose the number from the menu "
                 << "\n";
        }
    }
}
//-------------------------------
void Change_num_project_member(int user_index)
{
#define current_project_number App.USER[user_index].project_num
#define current_project_ App.USER[user_index].Project
    int project_i = found_project_index(user_index);
    if (project_i == -1)
    {
        Project_settings(user_index);
        return;
    }
    cout << "\n"
         << "\t"
         << "Ok you want to change the number of members of project "
         << current_project_[project_i].project_name
         << " !"
         << "\n";
    int temp = current_project_[project_i].num_of_project_members;
    get_project_members_num(user_index, project_i);
    cout << "\n"
         << "\t"
         << "Ok the number change fram " << temp << " to "
         << current_project_[project_i].num_of_project_members
         << " !"
         << "\n";
#undef current_project_number
#undef current_project_
}
//-------------------------------
void Change_name_project_leader(int user_index)
{
#define current_project_number App.USER[user_index].project_num
#define current_project_ App.USER[user_index].Project
    int project_i = found_project_index(user_index);
    if (project_i == -1)
    {
        Project_settings(user_index);
        return;
    }
    cout << "\n"
         << "\t"
         << "Ok you want to change the project "
         << current_project_[project_i].project_name
         << " name leader !"
         << "\n";
    string temp = current_project_[project_i].project_leader_name;
    get_project_leader_name(user_index, project_i);
    cout << "\n"
         << "\t"
         << "Ok the leader name change fram " << temp << " to "
         << current_project_[project_i].project_leader_name
         << " !"
         << "\n";

#undef current_project_number
#undef current_project_
}
//-------------------------------
void increase_project_salary(int user_index)
{
#define current_project_number App.USER[user_index].project_num
#define current_project_ App.USER[user_index].Project
    int project_i = found_project_index(user_index);
    if (project_i == -1)
    {
        Project_settings(user_index);
        return;
    }
    cout << "\n"
         << "\t"
         << "Ok you want to change the project "
         << current_project_[project_i].project_name
         << " salary !"
         << "\n";
    //-----
    string receved_num;
    float receved_number, temp_ = current_project_[project_i].project_salary;
    while (true)
    {
        cout << ">> Dear "
             << App.USER[user_index].first_name
             << " please enter the new salary project : ";

        getline(cin, receved_num);
        if (receved_num.length() < min_user_project)
            if (!interest_of_continue("\n\t sorry wrong input !  \n >> Do you want to try again it ?"))
            {
                Project_settings(user_index);
                return;
            }
            else
                continue;
        if ((count_condition_in_str(receved_num, '0', '9') == (receved_num.length() - 1) &&
             count_condition_in_str(receved_num, '.', '.') == 1) ||
            count_condition_in_str(receved_num, '0', '9') == receved_num.length())
        {
            receved_number = stof(receved_num);
            if (receved_number < current_project_number)
            {
                if (!interest_of_continue("\n\t sorry you can't enter lass than befor !  \n >> Do you want to try again it ?"))
                {
                    Project_settings(user_index);
                    return;
                }
                else
                    continue;
            }
            else
            {
                current_project_[project_i].project_salary = receved_number;
                break;
            }
        }
        else
        {
            if (!interest_of_continue("\n\t sorry wrong input :( \n\t make sure its carrect!\n >> Do you want to try again it ?"))
            {
                cout << "\n"
                     << "\t"
                     << "Something went wrong ! "
                     << "\n";
                Project_settings(user_index);
                break; //كاربر تمايل به ادامه ندارد
            }
        }
    }
    //----
    cout << "\n"
         << "\t"
         << "Ok the number change fram " << temp_ << " to "
         << current_project_[project_i].project_salary
         << " !"
         << "\n";
#undef current_project_number
#undef current_project_
}
//-------------------------------
void delete_project(int user_index)
{
#define current_project_number App.USER[user_index].project_num
#define current_project_ App.USER[user_index].Project
    if (current_project_number <= min_user_project)
    {
        cout << "\n"
             << "\t"
             << " Dear "
             << App.USER[user_index].first_name
             << " you have only one project you can't delete that"
             << "\n";
        Project_settings(user_index);
        return;
    }
    int project_num = found_project_index(user_index);
    if (project_num == -1)
    {
        Project_settings(user_index);
        return;
    }
    cout << "\n"
         << "\t"
         << ">> project "
         << current_project_[project_num].project_name
         << " deleted "
         << "\n";
    for (; project_num < current_project_number; project_num++)
    { //اطلاعات رو مرتب ميكينم
        move_user_project_info(project_num, project_num + 1);
    }
    current_project_number--; //حذف يك پروژه
#undef current_project_number
#undef current_project_
}
//-------------------------------
void print_user_settings_menu()
{
    cout << "\n " << emoji(50) << " Click Enter...";
    cin.get();
    system("cls");
    cout << "\n"
         << "1. Change your username"
         << "\n"
         << "2. Change your phone number"
         << "\n"
         << "3. Change your password"
         << "\n"
         << "4. Go back"
         << "\n"
         << "5. Logout"
         << "\n";
}
//-------------------------------
void user_settings(int user_index)
{
    while (true)
    {
        print_user_settings_menu();
        switch (get_command_code())
        {
        case 1:
            Change_user_username(user_index);
            break;
        case 2:
            Change_user_phonenumber(user_index);
            break;
        case 3:
            Change_user_password(user_index);
            break;
        case 4:
            info_settings(user_index);
            break;
        case 5:
            main_menu();
            break;
        default:
            cout << "\n"
                 << "\t"
                 << " please choose the number from the menu "
                 << "\n";
        }
    }
}
//-------------------------------
void Change_user_username(int user_index)
{
    string Current_usernNamr; //يوزرنيم كه درتابع از كاربر ميگيرد
    while (true)
    {
        cout << ">> Dear "
             << App.USER[user_index].first_name
             << " please enter the new username: ";
        getline(cin, Current_usernNamr);
        if (check_username(Current_usernNamr))
        {
            App.USER[user_index].username = Current_usernNamr; //ذخيره ي يوزرنيم ورودي
            break;
        }
        else
        {
            if (!interest_of_continue("\n\t sorry wrong input  :( \n >> Do you want to repeat it ?"))
            {
                cout << "\n"
                     << "\t"
                     << " task failed :( "
                     << "\n";
                user_settings(user_index);
                break; //كاربر تمايل به ادامه ندارد
            }
        }
    }
}
//-------------------------------
void Change_user_phonenumber(int user_index)
{
    string Current_PhoneNumber;
    while (true)
    {
        cout << ">> Dear "
             << App.USER[user_index].first_name
             << " please enter the new phone number: ";
        getline(cin, Current_PhoneNumber);
        if (check_phone_number(Current_PhoneNumber))
        {
            App.USER[user_index].phone_number = Current_PhoneNumber;
            break;
        }
        else
        {
            if (!interest_of_continue("\n\t sorry wrong input  :( \n >> Do you want to repeat it ?"))
            {
                cout << "\n"
                     << "\t"
                     << " task failed :( "
                     << "\n";
                user_settings(user_index);
                break; //كاربر تمايل به ادامه ندارد
            }
        }
    }
}
//-------------------------------
void Change_user_password(int user_index)
{
    while (true)
    {
        cout << ">>Dear "
             << App.USER[user_index].first_name
             << " please enter the previous password : ";
        string temp_password;
        getline(cin, temp_password);
        if (check_two_string(temp_password, App.USER[user_index].password) == false)
        {
            if (!interest_of_continue("\n\t Oh the password is not correct  :( \n >> Do you want to repeat it ? "))
                return; ////كاربر تمايل به ادامه ندارد
            else
                continue;
        }
        else
            break;
        cout << ">>Dear "
             << App.USER[user_index].first_name
             << " please enter the new password : ";
        getline(cin, temp_password);
        if (check_password(temp_password))
        {
            App.USER[user_index].password = temp_password; //ذخيره ي پسورد ورودي براي تاييد گرفتن
            break;
        }
        else
        {
            if (!interest_of_continue("\n\t sorry wrong input  :( \n >> Do you want to repeat it ?"))
            {
                cout << "\n"
                     << "\t"
                     << " task failed :( "
                     << "\n";
                user_settings(user_index);
                break; //كاربر تمايل به ادامه ندارد
            }
        }
    }
}
//-------------------------------
void print_Report_info_menu()
{
    cout << "\n " << emoji(50) << " Click Enter...";
    cin.get();
    system("cls");
    cout << " 1. Briefly report of projects"
         << "\n"
         << " 2. Advanced report of projects "
         << "\n"
         << " 3. Go back"
         << "\n"
         << " 4. Logout"
         << "\n";
}
//-------------------------------
void Report_info(int user_index)
{
    while (true)
    {
        print_Report_info_menu();
        switch (get_command_code())
        {
        case 1:
            Briefly_Report_projects_info(user_index);
            break;
        case 2:
            Advanced_Report_projects_info(user_index);
            break;
        case 3:
            login_first_menu();
            break;
        case 4:
            main_menu();
            break;
        default:
            cout << "\n"
                 << "\t"
                 << " please choose the number from the menu "
                 << "\n";
        }
    }
}
//-------------------------------
void Briefly_Report_projects_info(int user_index)
{
    cout << " you have " << App.USER[user_index].project_num;
    if (App.USER[user_index].project_num < 2)
        cout << " project ";
    else
        cout << " projects ";
    cout << "\n";
    for (int index = 0; index < App.USER[user_index].project_num; index++)
    {
#define temp_project_index App.USER[user_index].Project[index]
        cout << convertinteger2digit(index + 1) << "project : ";
        cout << "\n"
             << "\t"
             << " project name leader : "
             << temp_project_index.project_leader_name;
        cout << "\n"
             << "\t"
             << " project name : "
             << temp_project_index.project_name;
        cout << "\n"
             << "\t"
             << " number of project member  : "
             << temp_project_index.num_of_project_members;
        cout << "\n"
             << "\t"
             << " project all tasks durations : "
             << fixed << setprecision(4)
             << (temp_project_index.all_task_duration / 60).count()
             << " min";
        cout << "\n"
             << "\t"
             << " project id : "
             << temp_project_index.project_id;
        cout << "\n"
             << " this project has "
             << temp_project_index.task_num;
        if (temp_project_index.task_num < 2)
            cout << " task ";
        else
            cout << " tasks ";
        for (int i = 0; i < temp_project_index.task_num; i++)
        {
            cout << "\n"
                 << "\t\t"
                 << ">>task " << i + 1;
            cout << "\n"
                 << "\t\t"
                 << "\t"
                 << " task name "
                 << temp_project_index.task[i].task_name;
            {
                cout << "\n"
                     << "\t\t"
                     << "\t"
                     << " task duration "
                     << fixed << setprecision(4)
                     << (temp_project_index.task[i].task_duration / 60).count()
                     << " min";
                cout << "\n"
                     << "\t\t"
                     << "\t"
                     << " task id "
                     << temp_project_index.task[i].task_id;
            }
        }
        cout << endl;
    }
}
//-------------------------------
void Advanced_Report_projects_info(int user_index)
{
    int project_arry[max_user_project]; // انديس پروژه هاي انتخابي
    int max_tasks_user = max_tasks_num_users_project(user_index);

    int chosen_project_NUM = 0; //تعداد پروژه هاي انتخابي
    while (chosen_project_NUM < App.USER[user_index].project_num)
    {
        if (chosen_project_NUM != 0)
            if (!interest_of_continue("\n>> Do you want to add more ? "))
                break;

        cout << "\n"
             << " enter all to chose every project \n";

        int current_project_num = found_project_index(user_index); //  انديس پروژه

        if (current_project_num == -1)
            continue;
        if (App.USER[user_index].Project[current_project_num].task_num == 0)
        {
            cout << "\n \t > project  "
                 << App.USER[user_index].Project[current_project_num].project_name
                 << " has no task and it can't be use \n";
            continue;
        }
        if (current_project_num == -2)
        {
            chosen_project_NUM = 0;
            for (int i = 0, temp = 0, num = 0; i < App.USER[user_index].project_num; i++, num++)
            {
                if (App.USER[user_index].Project[i].task_num == 0)
                {
                    cout << "\n \t >-  "
                         << App.USER[user_index].Project[i].project_name
                         << " project has no task and it can't be use \n";

                    continue;
                }
                else
                {
                    project_arry[temp] = num;
                    chosen_project_NUM++;
                    temp++;
                }
            }
            break;
        }
        project_arry[chosen_project_NUM] = current_project_num;

        bool is_already_chosen = false;
        for (int i = 0; i < chosen_project_NUM; i++) //بررسي اينكه قبلا وارد نشده باشه
            if (project_arry[i] == project_arry[chosen_project_NUM])
            {
                is_already_chosen = true;
                break;
            }

        if (is_already_chosen)
        {
            cout << "\n this is already chosen  " << emoji(50) << "  \n";
            continue;
        }
        //قبلا مشابه نداشته    //يكي اضافه ميشه به تعداد
        chosen_project_NUM++;
    }
    cout << "\n>> " << chosen_project_NUM << " project are chosen \n";
    cout << "\n " << emoji(50) << " Click Enter to continue ...";
    cin.get();
    system("cls");
    int chosen_task_project[chosen_project_NUM][max_tasks_user];
    //گرفتن تسك ها
    int all_task_num = 0;
    for (int this_project_num = 0; this_project_num < chosen_project_NUM; this_project_num++)
    {
        int this_project_number = project_arry[this_project_num];
        if (App.USER[user_index].Project[this_project_number].task_num == 1)
        {
            cout << "\n \t>> project "
                 << App.USER[user_index].Project[this_project_number].project_name
                 << " has one task ( " << App.USER[user_index].Project[this_project_number].task[0].task_name
                 << " ) its counted  " << emoji(50) << " \n";
            chosen_task_project[this_project_num][0] = App.USER[user_index].Project[this_project_number].task_num;
            all_task_num++;
            this_project_num++;
            this_project_number = project_arry[this_project_num];
        }

        int task_arry[App.USER[user_index].Project[this_project_number].task_num] = {0};

        int task_num = 0; //task_num = 0
        while (task_num < App.USER[user_index].Project[this_project_number].task_num &&
               App.USER[user_index].Project[this_project_number].task_num != 0)
        {
            if (task_num != 0)
                if (!interest_of_continue("\n>> Do you want to add more ? "))
                    break;

            cout << "\n"
                 << " enter all to chose every task in project "
                 << App.USER[user_index].Project[this_project_number].project_name
                 << " \n";

            int current_task_index = found_task_index(user_index, this_project_number); //  انديس تسك پروژه

            if (current_task_index == -1)
                continue;

            if (current_task_index == -2)
            {
                task_num = 0;
                for (int i = 0;
                     i < App.USER[user_index].Project[this_project_number].task_num; i++)
                {
                    chosen_task_project[this_project_num][i] = task_num;
                    task_num++;
                }
                break;
            }

            task_arry[task_num] = current_task_index;
            bool is_already_chosen = false;
            for (int i = 0; i < task_num; i++) //بررسي اينكه قبلا وارد نشده باشه
                if (task_arry[i] == task_arry[task_num])
                {
                    is_already_chosen = true;
                    break;
                }

            if (is_already_chosen)
            {
                cout << "\n this is already chosen  " << emoji(50) << "  \n";
                continue;
            }
            chosen_task_project[this_project_num][task_num] = current_task_index;
            chosen_task_project[this_project_num][task_num];

            //قبلا مشابه نداشته    //يكي اضافه ميشه به تعداد
            task_num++;
        }

        all_task_num += task_num;
    }

    cout << "\n>> " << chosen_project_NUM << " project are chosen ";
    cout << "\n>> " << all_task_num << " tasks are chosen \n";
    cout << "\n " << emoji(50) << " Click Enter to continue ... " << ' ';
    cin.get();
    system("cls");

    //گرفتن زمان

    time_t min_start_time_projects = chrono::high_resolution_clock ::to_time_t(chrono::high_resolution_clock::now());
    for (int project_num = 0; project_num < chosen_project_NUM; project_num++)
    {
        int project_index = project_arry[project_num];
        if (min_start_time_projects > min_tasks_start_time_project(user_index, project_index))
            min_start_time_projects = min_tasks_start_time_project(user_index, project_index);
    }
    cout << "\n min_start_time_projects " << ctime(&min_start_time_projects);
    time_t max_end_time_projects = 0;
    for (int project_num = 0; project_num < chosen_project_NUM; project_num++)
    {
        int project_index = project_arry[project_num];

        if (max_end_time_projects < max_tasks_end_time_project(user_index, project_index))
            max_end_time_projects = max_tasks_end_time_project(user_index, project_index);
    }
    cout << "\n max_end_time_projects " << ctime(&max_end_time_projects);
    //گرفتن زمان مبدا

    time_t bigan_time_t_, min_time_that_user_input = min_start_time_projects -= 1;
    time_t finish_time_t_, max_time_that_user_input = max_end_time_projects + 1;
    while (true)
    {
        while (true)
        {
            bigan_time_t_ = 0;
            cout << "\n\t >> enter the beginning time point "
                 << "\n ex. 2029-09-15 or 2213.12.03 or 1999/01/31 or yyyy?mm?dd "
                 << "\n for choosing the minimum tasks time point enter '0' "
                 << ctime(&min_start_time_projects)
                 << "\n >> type : ";

            string ans;
            cin >> ans;
            cin.get();
            for (int i = 0; ans[i] != '\0'; i++)
                ans[i] -= '0';
            if (ans[0] == 0)
            {
                bigan_time_t_ = min_start_time_projects;

                break;
            }
            int year_ = ans[0] * 1000 + ans[1] * 100 + ans[2] * 10 + ans[3]; //year
            if (!(year_ > 1971) && year_ < t_this_year + 1)
            {
                cout << "\n\t> worng year ( " << year_ << " ) try again \n";
                continue;
            }
            double tt_yy = (year_ - 1970) * 3.1556952e+7; //one year is 3.154e+7 seconds

            //ans[4] ولش

            int month_ = ans[5] * 10 + ans[6]; //month

            if (!(month_ <= 12 && month_ >= 1))
            {
                cout << "\n\t> worng month ( " << month_ << " ) try again \n";
                continue;
            }
            double tt_mm = (month_)*2629746; //one month is 2.628e+6 second

            //ans[7]ولش

            int day_ = ans[8] * 10 + ans[9]; //day
            if (!(day_ <= 31 && day_ >= 0))
            {
                cout << "\n\t> worng day ( " << day_ << " ) try again \n";
                continue;
            }

            double tt_dd = (day_)*86400; //one day 86400 s

            double tt_add = tt_yy + tt_mm + tt_dd; //ميزان كه بايد اضافه بشه

            if (tt_add < 1)
            {
                cout << "\n\t> worng input try again \n";
                continue;
            }

            bigan_time_t_ += tt_add;

            break;
        }

        while (true)
        {
            finish_time_t_ = 0;
            cout << "\n\t >> enter the finishing time point "
                 << "\n ex. 2029-09-15 or 2213.12.03 or 1999/01/31 or yyyy?mm?dd "
                 << "\n for choosing the maximum tasks time point enter '0' "
                 << ctime(&max_end_time_projects)
                 << "\n >> type : ";

            string ans;
            cin >> ans;
            cin.get();
            for (int i = 0; ans[i] != '\0'; i++)
                ans[i] -= '0';
            if (ans[0] == 0)
            {
                finish_time_t_ = max_end_time_projects;

                break;
            }
            int year_ = ans[0] * 1000 + ans[1] * 100 + ans[2] * 10 + ans[3]; //year
            if (!(year_ > 1971))
            {
                cout << "\n\t> worng year ( " << year_ << " ) try again \n";
                continue;
            }
            double tt_yy = (year_ - 1970) * 3.1556952e+7; //one year is 3.154e+7 seconds

            //ans[4] ولش

            int month_ = ans[5] * 10 + ans[6]; //month

            if (!(month_ <= 12 && month_ >= 1))
            {
                cout << "\n\t> worng month ( " << month_ << " ) try again \n";
                continue;
            }
            double tt_mm = (month_)*2629746; //one month is 2.628e+6 second

            //ans[7]ولش

            int day_ = ans[8] * 10 + ans[9]; //day
            if (!(day_ <= 31 && day_ >= 0))
            {
                cout << "\n\t> worng day ( " << day_ << " ) try again \n";
                continue;
            }

            double tt_dd = (day_)*86400; //one day 86400 s

            double tt_add = tt_yy + tt_mm + tt_dd; //ميزان كه بايد اضافه بشه

            if (tt_add < 1)
            {
                cout << "\n\t> worng input try again \n";
                continue;
            }

            finish_time_t_ += tt_add;
            break;
        }
        if (finish_time_t_ < bigan_time_t_)
            cout << "\n the biganing time " << ctime(&bigan_time_t_)
                 << " is greater than finishing time " << ctime(&finish_time_t_);
        else
            break;
    }

    cout << "\n bigging time set for " << ctime(&bigan_time_t_);
    cout << "finishing time set for " << ctime(&finish_time_t_);
    int x;
    string xs;
    cout << "\n 1.month     2.day      3.hour      4.minet \n type the number :";
    cin >> x;
    switch (x)
    {
    case 1:
        x = 2629746;
        xs = "month";
        break;
    case 2:
        x = 86400;
        xs = "day";
        break;
    case 3:
        x = 3600;
        xs = "hour";
        break;
    case 4:
        x = 60;
        xs = "minute";
        break;
    default:
        x = 2629746;
        xs = "month";
        break;
    }

    cout << emoji(42) << " time->" << xs;
    for (int i; bigan_time_t_ < finish_time_t_; bigan_time_t_ += x, i++)
    {
        cout << "\n ┤ ";
        for (int j = 0; chosen_task_project[i][j] != '\0'; j++)
        {
            if (finish_time_t_ <= max_tasks_end_time_project(user_index,i) && 
            bigan_time_t_ >= min_tasks_start_time_project(user_index,i))
            cout<<"#";
        }
        cout<<endl;
    }
    cout << "\n--------------------------------------------------" << emoji(2) << " number";
    cout << "\n " << emoji(50) << " Click Enter to continue ...";
    cin.get(); cin.get(); cin.get();
    system("cls");
    cout
        << "\n done \n";
}
//--------------
void move_user_project_info(int origin, int destination)
{
#define temp_origin App.USER[logged_user_index].Project[origin]
#define temp_destination App.USER[logged_user_index].Project[destination]
    temp_origin.num_of_project_members =
        temp_destination.num_of_project_members;

    temp_origin.project_salary = 
    temp_destination.project_salary;

    temp_origin.project_leader_name =
     temp_destination.project_leader_name;

    temp_origin.project_name = 
    temp_destination.project_name;

    temp_origin.project_id =
     temp_destination.project_id;

    temp_origin.task_num = 
    temp_destination.task_num;

    for (int i = 0; i < temp_destination.task_num; i++)
    {
        temp_origin.task[i].task_id =
            temp_destination.task[i].task_id;
        temp_origin.task[i].task_name =
            temp_destination.task[i].task_name;
        temp_origin.task[i].task_start_point =
            temp_destination.task[i].task_start_point;
        temp_origin.task[i].task_end_point =
            temp_destination.task[i].task_end_point;
        temp_origin.task[i].task_duration =
            temp_destination.task[i].task_duration;
    }
#undef temp_origin
#undef temp_destination
}
//-------------------------------
string convertinteger2digit(int n)
{
    string number;
    string FirstDigit[] = {"", "First ", "Second ", "Third ", "Fourth ", "Fifth ",
                           "Sixth ", "Seventh ", "Eightth ", "Ninth ", "Tenth ", "Eleventh ",
                           "Twelfth ", "Thirteenth ", "Fourteenth ", "Fifteenth ",
                           "Sixteenth ", "Seventeenth ", "Eighteenth ", "Nineteenth "};
    string SecendDigit[] = {"", "", "Twentieth ", "Thirtieth ", "Fortieth ", "Fiftieth ",
                            "Sixtieth ", "Seventieth ", "Eightieth ", "Ninetieth "}; //براي كمتر 10 از بالايي استفاده ميكني

    if (n >= 20)
    {
        number = SecendDigit[n / 10] + FirstDigit[n % 10];
    }
    else
    {
        number = FirstDigit[n];
    }
    return number;
}
//--------
int max_tasks_num_users_project(int user_index)
{
    int ANS = 0; //answer
    for (int i = 0; i < App.USER[user_index].project_num; i++)
        ANS = max(ANS, App.USER[user_index].Project[i].task_num);
    return ANS;
}

time_t max_tasks_end_time_project(int user_index, int project_index)
{
    time_t MAX = App.USER[user_index].Project[project_index].task[0].task_end_point;
    for (int i = 1; i < App.USER[user_index].Project[project_index].task_num; i++)
        if (MAX < App.USER[user_index].Project[project_index].task[i].task_end_point)
            MAX = App.USER[user_index].Project[project_index].task[i].task_end_point;
    return MAX;
}

time_t min_tasks_start_time_project(int user_index, int project_index)
{
    time_t MIN = App.USER[user_index].Project[project_index].task[0].task_start_point;
    for (int i = 1; i < App.USER[user_index].Project[project_index].task_num; i++)
        if (App.USER[user_index].Project[project_index].task[i].task_start_point < MIN)
            MIN = App.USER[user_index].Project[project_index].task[i].task_start_point;
    return MIN;
}