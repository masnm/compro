#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long
#define ld long double

#define chmax(a,b) if ( a < b ) a = b
#define chmin(a,b) if ( a > b ) a = b

void prepare_lookup_table ()
{
}

struct user {
	char name[101];
	char pin[101];
} usr ;

void print_welcome_message ()
{
	printf("\tWelcome to rail ticket buying system.\n\n");
	printf("This program is written by ");
	printf("Your Name (AIUB Student id)\n");
	printf("To use this program as a user you need to register first.");
	printf("Then login will appear automatically.\n");
	printf("Once you login successfully it will show the option to buy ticket.\n");
	printf("\n");
}

int reg_or_log ()
{
	printf("Already an user ?\n");
	printf("1 . Login\n");
	printf("2 . Regrestation\n");
	printf("Enter Your choice : ");
	int x;
	scanf("%d",&x);
	while ( x < 1 || x > 2 ) {
		printf("Wrong Choice. Try again : ");
		scanf("%d",&x);
	}
	return x;
}

void registration_page ()
{
	printf("\n\nRegistration : \n");
	printf("Enter a username : ");
	scanf("%s",usr.name);
	printf("Enter 3 digit pin number : ");
	bool vpin = false;
	while ( !vpin ) {
		scanf("%s",usr.pin);
		int len = strlen(usr.pin);
		if ( len == 0 ) {
			printf("Invalid Pin.Try again : ");
		} else if ( len > 3 ) {
			printf("Invalid Pin.Try again : ");
		} else if ( len < 3 ) {
			printf("Invalid Pin.Try again : ");
		} else {
			bool not_pin = false;
			for ( int i = 0 ; i < len ; i++ ) {
				if ( usr.pin[i] < '0' || usr.pin[i] > '9' ) {
					not_pin = true;
					break;
				}
			}
			if ( not_pin ) {
				printf("Invalid Pin.Try again : ");
			} else {
				vpin = true;
			}
		}
	}
	FILE* fp = fopen ( "user.txt", "w" );
	fprintf ( fp, "%s\n", usr.name );
	fprintf ( fp, "%s\n", usr.pin );
	fclose(fp);
}

bool retrive_info ()
{
	char nm[101], pn[101];
	FILE* fp = fopen ( "user.txt", "r" );
	if ( fscanf( fp, "%s", nm ) == EOF ) {
		return false;
	}
	if ( fscanf( fp, "%s", pn ) == EOF ) {
		return false;
	}
	strcpy ( usr.name, nm );
	strcpy ( usr.pin, pn );
	fclose ( fp );
	return true;
}

bool valid_user ()
{
	char nm[101], pn[101];
	printf("Enter User Name : ");
	scanf("%s",nm);
	printf("Enter 3 digit pin number : ");
	scanf("%s",pn);
	return strcmp(nm,usr.name) == 0 && strcmp(pn, usr.pin) == 0;
}

int price[] = {100,120,150,180,220,250};
void show_route ()
{
	printf("All available route and price.\n");
	printf("1 . Dhaka to Bhairab Bazar bdt 100.\n");
	printf("2 . Dhaka to Brahman Baria bdt 120.\n");
	printf("3 . Dhaka to Comilla bdt 150.\n");
	printf("4 . Dhaka to Laksam bdt 180.\n");
	printf("5 . Dhaka to Feni bdt 220.\n");
	printf("6 . Dhaka to Chittagong bdt 250.\n");
	printf("Enter Your choice : ");
	int x;
	scanf("%d",&x);
	while ( x < 1 || x > 6 ) {
		printf("Wrong Choice. Try again : ");
		scanf("%d",&x);
	}
	int cnt;
	printf("Enter the number of ticket.\n");
	scanf("%d",&cnt);
	while ( cnt < 1 ) {
		printf("Invalid input. Try again : ");
		scanf("%d",&cnt);
	}
	printf("Total price : %d\n",price[x-1]*cnt);
	printf("Enter payment of tickets : ");
	int pmnt;
	scanf("%d",&pmnt);
	while ( pmnt != price[x-1]*cnt ) {
		printf("Not matched. Try again : ");
		scanf("%d",&pmnt);
	}
	printf("Payment successfull. Thank you for using the system.\n");
	return;
}

void serve_menu ()
{
	printf("Menu list.\n");
	printf("1 . Buy Ticket.\n");
	printf("2 . Exit.\n");
	printf("Enter Your choice : ");
	int x;
	scanf("%d",&x);
	while ( x < 1 || x > 2 ) {
		printf("Wrong Choice. Try again : ");
		scanf("%d",&x);
	}
	if ( x == 2 ) return;
	show_route ();
}

void login_page ()
{
	printf("\n\nLogin : \n");
	if ( !retrive_info() ) {
		printf("Failed to retrive user info.");
		printf("Register again.");
		return;
	}
	int count = 0;
	while ( !valid_user() && count++<5 ) {
		printf("Username or pin is invalid\n");
		printf("Try again.\n");
	}
	if ( count > 5 ) return;
	else printf("Login success.\n");

	serve_menu ();
}

void do_task ()
{
	print_welcome_message ();
	int rl = reg_or_log ();
	if ( rl == 1 ) {
		login_page ();
	} else {
		registration_page ();
		login_page ();
	}
}

int main ()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);

	prepare_lookup_table();

	ll t = 1;
//	cin >> t;
	while ( t-- ) {
		do_task();
	}


	return 0;
}
