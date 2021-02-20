#pragma once
//---------- project فهرست اسم توابع
#include <iostream> //for useing c++ code
#include <string.h> //براي استفاده از رشته
#include <iomanip>  //براي استفاده از اعشار
#include <chrono>   // براي استفاده از زمان
using namespace std;
//------------
const int len_max_user = 100;
const int lenmin = 2;
const int lenmaxgneral = 100;
const int lenmaxName = 20;        //طول اسم و فاميل
const int lenmaxPhoneNumber = 11; //طول شماره تلفن
const int lenmaxUsername = 7;     //طول يوزرنيم
const int lenmaxPassword = 13;    //ماكسيمم طول پسورد
const int lenminPassword = 8;     //مينيم طول پسورد
const int max_user_project = 10;  //ماكسيمم پروژه هاي كاربر
const int min_user_project = 1;   //مينيم پروژه هاي كاربر
const int t_this_year=2021;
//------------ركوردها

//اطلاعات تسک
struct task_info
{
    int task_id = 100;
    string task_name;
    time_t task_start_point;                //زمان شروع تسك
    time_t task_end_point;                  //زمان پايان تسك
    chrono::duration<double> task_duration; //طول تسك
};

//مشخصات اطلاعات پروژه
struct projects_info
{
    int task_num = 0; //تعداد تسك هاي كاربر
    int project_id = 100;
    int num_of_project_members = 0; //تعداد اعضاي پروژه
    float project_salary;           // ميزان حقوق دلار بر ساعت
    string project_leader_name;     // رييس تيم در پروژه
    string project_name;            // اسم پروژه//ارايه است
    task_info task[lenmaxgneral];
    chrono::duration<double> all_task_duration;
};

//مشخصات اطلاعات کاربران
struct User_info
{
    int user_id = 100;
    string first_name;                       //اسم كاربر
    string last_name;                        //فاميل كاربر
    string phone_number;                     //شماره تلفن كاربر
    string username;                         //يوزرنيم كاربر
    string password;                         //پسورد كاربر
    projects_info Project[max_user_project]; //ارايه اي براي پروژه
    int project_num = 0;                     //تعداد پروژه هاي كاربر
};
//----------------------------
//ساخت ايموجي
char emoji(int x);
/**
 * بررسي عدد بودن كد - 
 * در يافت كد از كاربر 
 * @return int command code
 */
int get_command_code();
/**
 *    چاپ   
 *    1.singup
 *    2.login  
 *    3.exit 
 */
void print_main_menu();
/**
 * print_main_menu(); رفتن به 
 * دريافت عدد
 * 1-> singup();
 * 2-> login_entery();
 * 3-> exit(0);
 */
void main_menu();
/**
 * انجام تابع هاي زير -
 *  get_first_name
 *  get_last_name
 *  get_phone_number
 *  get_username
 *  get_password
 *  get_password_confiorm 
 *  اضافه كردن به تعداد كاربران اگر مراحل بالا انجام شد
 *   main_menu(); رفتن به
 */
void singup();
/**
 * @brief Get the user first name and save it in struct
 * @param int is user index
 */
void get_first_name(int);
/**
 * @brief Get the user last name and save it in struct
 * @param int is user index
 */
void get_last_name(int);
/**
 * @brief Get the user phone number and save it in struct
 * @param int is user index
 */
void get_phone_number(int);
/**
 * @brief Get the user username and save it in struct
 * @param int is user index
 */
void get_username(int);
/**
 * @brief Get the user password and save it in struct
 * @param int is user index
 */
void get_password(int);
/**
 * @brief Get the user password confiorm 
 * @param int is user index
 */
void get_password_confiorm(int);
/**
 *  بررسي شرايط زير -
 *  lenmaxName - 
 *  lenmin -
 * نبود عدد در ان -
 * @param input رشته ي ورودي
 * @return true when all condition was true 
 * @return false 
 */
bool check_name(string input);
/**
 * بررسي شرايط زير -
 * قبلا وجود نداشته باشه-
 * طول از 11 رقم باشه-
 * با 09 شروع شود-
 * @param input رشته ي ورودي 
 * @return true when all condition was true
 * @return false 
 */
bool check_phone_number(string input);
/**
 * بررسي شرايط زير -
 * قبلا وجود نداشته باشه-
 * طول از 7 رقم باشه-
 * با 9 شروع شود-
 * با 3 يا 5 تمام شود-
 * @param input رشته ي ورودي 
 * @return true when all condition was true
 * @return false 
 */
bool check_username(string input);
/**
 *  بررسي شرايط زير -
 *  lenmaxPassword - 
 *  lenminPassword -
 * حداقل يه حرف بزرگ -
 * حداقل يه حرف كوچك -
 * حداقل يه عدد -
 * @param input رشته ي ورودي
 * @return true when all condition was true 
 * @return false 
 */
bool check_password(string input);
/**
 * @brief بررسي يكسان بودن دو رشته
 * @param input1 رشته اول
 * @param input2 رشته دوم
 * @return true يكسان بود
 * @return false يكسان نبود
 */
bool check_two_string(string input1, string input2);
/**
 * @brief بررسي اينكه قبلا وجود داشته يا نه
 * @param input شماره تلفن
 * @return -1 وقتي قبلا وجود نداشت --- index وقتي وجود داشت انديس كاربر 
 */
int found_phonenumber(string input);
/**
 * @brief بررسي اينكه قبلا وجود داشته يا نه
 * @param input يوزرنيم
 * @return 
 * -1 وقتي قبلا وجود نداشت --- 
 * index وقتي وجود داشت انديس كاربر 
 */
int found_username(string input);
/**
 * ايا كاربر تمايل به ادامه دارد---
 * y = yes - n =no 
 * @param massage متن سوال همون پيامي كه چاپ ميشود 
 * @return true  علاقه به ادامه دارد  --- false علاقه به ادامه ندارد
 */
bool interest_of_continue(string massage);
//------------------------------------
/**
 * //شمارش تعداد خانه هايي از رشته كه شرط بين "شروع "و""پايان" را دارند
 * @param input رشته ورودي
 * @param start عنصر شروع
 * @param end عنصر پايان
 * @return int تعداد خانه هايي كه شرط را داشت
 */
int count_condition_in_str(string input, char start, char end);
/**
 * // خانه اي در رشته كه حداقل شرط بين "شروع "و""پايان" را دارد 
 * @param input رشته ورودي
 * @param start عنصر شروع
 * @param end عنصر پايان 
 * @return true وجود داشت
 * @return false وجود نداشت
 */
bool have_condition_in_str(string input, char start, char end); //فرق ان با تابع قبلي اين است كه سرعتش بيشتر هست
//------------------------------

/**
 * گرفتن يوزرنيم
 * بررسي اينكه يوزرنيم قبلا وجود نداشته باشه
 * گرفتن پسورد
 * بررسي درستيه پسورد
 * شرايط بالا برقرار بود
 * login_first_menu(); رفتن به
 */
void login_entery();
/**
 * چاپ 
//   1. Create a new project
//   2. Create a new task
//   3. settings
//   4. See Reports
//   5. Logout
//   6. Exit 
 */
void print_login_first_menu();
/**
 * print_login_first_menu(); رفتن به 
 * دريافت كامند كد
 * 5->main_menu();
 * 6-> exit(0);
 * درصورت نداشتن پروژه يك پروژه بگيرد
 * 1-> Create_new_project();
 * 2-> پيدا كردن انديس پروژه
 *  Create_task(); رفتن به
 * 3-> info_settings();
 * 4-> Report_info();
 */
void login_first_menu();
/**
 * ساخت پروژه 
 * رفتن به تابع هاي زير-
  get_project_name --
  get_project_members_num--
  get_project_leader_name--
  get_project_salary--
  اگر تمام انها انجام شد --
  زمان پروژه رو صفر ميكنه-
  تعداد پروژه ها يكي اضافه ميشود-
  * @param  user_index user index
 */
void Create_new_project(int user_index);
/**
 * @brief Get the project name -
 * ذخيره ي اسم در ركورد خود -
 * بررسي وجود نداشت اسم -
 * اسم پروژه all نباشد -
 * login_first_menu(); پس از اتمام رفتن به -
 * @param user_index is user index
 * @param project_i the project index
 */
void get_project_name(int user_index, int project_i);
/**
 * بررسي وجود نداشت اسم قبلا -
 * all نبايد اسم باشد -
 * @param user_index user index
 * @param input string of project name
 * @return true اگر شرط برقرار بود
 * @return false 
 */
bool check_project_name(int user_index, string input);
/**
 * @brief Get the project members number  -
  * ذخيره ي عدد در ركورد خود -
  * login_first_menu(); پس از اتمام رفتن به -
 * @param user_index is user index
 * @param project_i the project index 
 */
void get_project_members_num(int user_index, int project_i);
/**
 * @brief Get the project leader name  -
 * ذخيره ي اسم رييس در ركورد خود -
 * login_first_menu(); پس از اتمام رفتن به -
 * @param user_index is user index
 * @param project_i the project index
 */
void get_project_leader_name(int user_index, int project_i);
/**
 * @brief Get the project salary  -
 * ذخيره ي مقدار دستمزد در ركورد خود -
 * login_first_menu(); پس از اتمام رفتن به -
 * @param user_index is user index
 * @param project_i the project index
 */
void get_project_salary(int user_index, int project_i);
/**
 * print_project_names(user_index); رفتن به -
 * بررسي اسم گرفته شده -
 * پيدا كردن انديس پراجكت -
 * @param user_index is user index
 * @return int -1 اگر نباشد ---
 *  index project وقتي وجود داشت ----
 * -2 وقتي همه انتخاب شد ---
 */
int found_project_index(int user_index);
/**
 * چاپ اسم پروژه هاي كاربر 
 * @param user_index is user index
 */
void print_project_names(int user_index);
/**
 * گرفتن اسم تسك
 * @param user_index is user index
 * @param project_index is project index
 * @return int -1 اگر نباشد --- 
 * int index task وقتي وجود داشت----
 * int -2 وقتي همه انتخاب شد ---
 */
int found_task_index(int user_index, int project_index);
/**
 * چاپ اسم تسك ها
 * @param user_index is user index
 * @param project_index is project index
 */
void print_task_names(int user_index, int project_index);
/**
 *  گرفتن زمان شروع -
 * گرفتن زمان پايان -
 * محاسبه مدت زمان تسك -
 * ذخيره كردن اطلاعات بالا -
 * اضافه كردن زمان به زمان پروژه -
 * اضافه كردن به تعداد تسك ها -
 * @param user_index user index
 * @param current_project_num_intiger project index 
 */
void Create_task(int user_index, int current_project_num_intiger);
/**
* چاپ ---
* 1. projects settings -
* 2. user settings -
* 3. Go back -
* 4. Logout -
 */
void print_info_settings_menu();
/**
 * print_info_settings_menu(); رفتن به  
 * 1->Project_settings(); -
 * 2->user_settings(); -
 * 3->login_first_menu(); -
 * 4->main_menu(); -

 * @param user_index is user index 
 */
void info_settings(int user_index);
/**
*   1. Change the amount of project members
*   2. Change the name of project leader
*   3. Increase the salary of project
*   4. Delete a project
*   5. Go back
*   6. Logout
*/
void print_project_settings_menu();
/** 
 * 1-> Change_num_project_member(user_index); --
 * 2->Change_name_project_leader(user_index); --
 * 3->increase_project_salary(user_index); --
 * 4->delete_project(user_index); --
 * 5->info_settings(user_index); --
 * 6->main_menu(); -
 * @param user_index is user index
 */
void Project_settings(int user_index);
/**
  * found_project_index(user_index);پيدا كردن انديس پروژه در 
  *  Change number of project member
  * @param user_index is user index
  */
void Change_num_project_member(int user_index);
/**
  * found_project_index(user_index);پيدا كردن انديس پروژه در 
  *  Change name of project leader
  * @param user_index is user index
  */
void Change_name_project_leader(int user_index);
/**
  * found_project_index(user_index);پيدا كردن انديس پروژه در 
  * increase project salary
  * @param user_index is user index
  */
void increase_project_salary(int user_index);
/**
  * found_project_index(user_index);پيدا كردن انديس پروژه در  
  * قبل بردن پروژه هاي جلو تر ان
  * يكي كم كردن تعداد پروژه ها 
  * @param user_index is user index
  */
void delete_project(int user_index);
/**
 * 1. Change your username 
 * 2. Change your phone number
 * 3. Change your password 
 * 4. Go back 
 * 5. Logout 
 */
void print_user_settings_menu();
/** 
 * print_user_settings_menu(); رفتن به --
 * 1->Change_user_username(user_index);  --
 * 2->Change_user_phonenumber(user_index);  --
 * 3->Change_user_password(user_index);  --
 * 4->info_settings(user_index);  --
 * 5->main_menu(); --
 * @param user_index is user index
 */
void user_settings(int user_index);
/**
 * دريافت و بررسي يورزنيم جديد
 * Change user username 
 * @param user_index is user index
 */
void Change_user_username(int user_index);
/**
 * دريافت و بررسي شماره تلفن جديد
 * Change user phonenumber 
 * @param user_index is user index
 */
void Change_user_phonenumber(int user_index);
/**
 * دريافت پسورد قبلي و بررسي ان با پسورد فعلي
 * دريافت پسورد جديد و بررسي
 * ذخيره ان در ركورد خود
 * @param user_index is user index
 */
void Change_user_password(int user_index);
/**
//  1. Briefly report of projects
//  2. Advanced report of projects
//  3. Go back
//  4. Logout
*/
void print_Report_info_menu();
/**
 * print_Report_info_menu(); رفتن به  
 * 1-> Briefly_Report_projects_info(user_index);
 * 2-> Advanced_Report_projects_info(user_index);
 * 3-> login_first_menu();
 * 4-> main_menu();
 *  @param user_index is user index
 */
void Report_info(int user_index);
/**
 *  چاپ اطلاعات پروژه ها
 *  اسم رييس پروژه 
 *  اسم پروژه
 *  تعداد اعضاي پروژه
 *  دستمزد پروژه
 *  مدت زمان در پروژه
 *  project id
 *  چاپ اطلاعات تسك ها
 *  اسم تسك
 *  مدت زمان تسك
 *  task id
 *  @param user_index is user index
 */
void Briefly_Report_projects_info(int user_index);
//* @param user_index is user index
void Advanced_Report_projects_info(int user_index);
/**
 *  اطلاعات پروژه مبدا  رو داخل  مقصد قرار ميدهد   

 * @param origin مبدا
 * @param destination مقصد
 */
void move_user_project_info(int origin, int destination);
/**
 * //تبديل اعداد دورقمي به اسم اون عدد 
 * @param num عدد وروردي
 * @return string اسم اون عدد
 */
string convertinteger2digit(int num);
/**
 * محاسبه بزرگترين تعداد تسك پروژه هاي كاربر 
 * @param user_index is user index 
 * @return بيشترين تعداد تسك
 */
int max_tasks_num_users_project(int user_index);
/**
 * محاسبه ی ماکسیم زمان پایانی پروژه 
 * @param user_index is user index 
 * @param project_index انديكس پروژه
 * @return time_t زمان بيشترين
 */
time_t  max_tasks_end_time_project(int user_index, int project_index);
/**
 * محاسبه ی مينيم زمان شروع پروژه 
 * @param user_index is user index 
 * @param project_index انديكس پروژه
 * @return time_t زمان كمترين
 */
time_t min_tasks_start_time_project(int user_index, int project_index);


//اطلاعات اپ
struct APP
{
    User_info USER[len_max_user]; //ارايه هاي كاربران
    int Users_num = 000;          //انديس اخرين فرد ثبت نام كرده
};
