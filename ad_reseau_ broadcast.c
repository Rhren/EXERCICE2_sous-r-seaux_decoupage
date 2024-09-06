#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



char *convert_binaire(int number,char *chaine)
{
	
	int i;
	int r=128;
	
	
	for(i=7 ; i>=0 ;i--)
	{
		if(r > number)
		{
			strcat(chaine,"0");
			r=r-pow(2,i)+pow(2,i-1);
		}
		else
		{
			r=r+pow(2,i-1);
			strcat(chaine,"1");
		
		}
		
	}
	
	return chaine;
}
int decimal(char *dix)
{
	int somme=0;
	int j=7;
	int k=0;
	while(dix[j]  != '\0')
	{
		if(dix[j]  == '1')
		{
			somme=pow(2,k) + somme;
			
		}
			
		j--;
		k++;
	}	
	return somme;	
}
char *broadcast(int new_mask,char *ad_reseau,char *ad_broadcast)
{

	int i=0;
	
	int count=1;
	while(ad_reseau[i] != '\0' && count <= 32)
	{
		if(count <= new_mask)
		{
			ad_broadcast[i]=ad_reseau[i];
		}
		else
		{
			ad_broadcast[i]='1';
			
		}
		i++;
		count++;
	}
	
	
	return (ad_broadcast);
	
}
void netmask(int nbr_reseau,char *ip)
{
	char copy_ip[20]="";
	char bits_reseau[33]="";
	int i;
	
	for(i=1 ; i<= nbr_reseau ; i++)
	{
		strcat(bits_reseau,"1");
		
	}
	for(i=nbr_reseau ; i<32 ;i++)
	{
		strcat(bits_reseau,"0");
	}
	
//-------------------------------

	char *one;
	char *two;
	char *three;
	char *four;
	char ch[10]="";
	char bin_ip[40]="";
	char bin_t[10]="";
	char bin_th[10]="";
	int first;
	int scd;
	int third;
	int  end;
	int j=0;
	char ad_reseau[33]="";
	char ad_bcast[33]="";
	char ad_broadcast[33]="";
	
	strcpy(copy_ip,ip);
	
	one=strtok(copy_ip,".");
	two=strtok(NULL,".");
	three=strtok(NULL,".");
	four=strtok(NULL,".");
		
	first=atoi(one);
	scd=atoi(two);
	third=atoi(three);
	end=atoi(four);
	
	convert_binaire(first,bin_ip);
	strcat(bin_ip,convert_binaire(scd,bin_t));
	strcat(bin_ip,convert_binaire(third,bin_th));
	strcat(bin_ip,convert_binaire(end,ch));
	
//-----------------------------------------------------------

	while(bin_ip[j] != '\0' && bits_reseau[j] != '\0')
	{
		if(bin_ip[j] == '0' || bits_reseau[j] == '0')
		{
			ad_reseau[j]= '0';
			
		}
		else
		{
			ad_reseau[j]= '1';
		}
		j++;
	}
	
//-------------------------------------------------------------------------------
	int num=1;
	int k=0;
	int count=1;
	int n;
	int new_mask;
	char ad_br[40]="";
	while(ad_reseau[k] != '\0' && count <= 32)
	{
		if(count <= nbr_reseau)
		{
			ad_bcast[k]=ad_reseau[k];
			
		}
		else
		{
			ad_bcast[k]='1';
			
		}
		count++;
		k++;
	}
//-----------------------------------------------	
	do
	{
		printf("Entrer le nombre de decoupe: ");
		scanf("%d",&n);
		new_mask=nbr_reseau + n;
		
	}while(new_mask >= 31 || n < 0);
	
//--------------------------------------------	
	char fi[9]="";
	char tw[9]="";
	char th[9]="";
	char fo[9]="";
	
	char uno[9]="";
	char t[9]="";
	char thr[9]="";
	char fr[9]="";
	int pc=pow(2,32-new_mask)-2;
	
	do
	{
			
			strcpy(ad_broadcast,broadcast(new_mask,ad_reseau,ad_br));
			
			strncpy(fi,ad_reseau,8);
			strncpy(tw,ad_reseau+8,8);
			strncpy(th,ad_reseau+16,8);
			strncpy(fo,ad_reseau+24,8);
			
			int premier=decimal(fi);
			int deux=decimal(tw);
			int trois=decimal(th);
			int quatre=decimal(fo);
			
			strncpy(uno,ad_broadcast,8);
			strncpy(t,ad_broadcast+8,8);
			strncpy(thr,ad_broadcast+16,8);
			strncpy(fr,ad_broadcast+24,8);
			
			int primo=decimal(uno);
			int dx=decimal(t);
			int trs=decimal(thr);
			int qtr=decimal(fr);
			


			
			printf("   **Sous reseau %d:\n ",num);
			printf("adresse reseau:     %d.%d.%d.%d \n",premier,deux,trois,quatre);
			printf("adresse broadcast:  %d.%d.%d.%d \n",primo,dx,trs,qtr);
			printf("Nombre de machine:  %d\n\n",pc);

			if(qtr == 255)
			{
				qtr = 0;
				if(trs == 255)
				{
					trs = 0;
					
					if(dx == 255)
					{
						dx = 0;
						primo=primo+1;
					}
					else
					{
						dx=dx+1;
					}
				}
				else
				{
					trs=trs+1;
				}
			}
			else
			{
				qtr=qtr+1;
			}

			sprintf(ad_reseau,"%d.%d.%d.%d",primo,dx,trs,qtr);
			
			char *first_ad;
			char *scd_ad;
			char *third_ad;
			char  *fr_ad;
			
			char bin_huit[9]="";
			char bin_seize[9]="";
			char bin_vqtr[9]="";
			char bin_trdx[9]="";
			
			int huit;
			int seize;
			int vqtr;
			int trdx;

			first_ad=strtok(ad_reseau,".");
			scd_ad=strtok(NULL,".");
			third_ad=strtok(NULL,".");
			fr_ad=strtok(NULL,".");
			
			huit=atoi(first_ad);
			seize=atoi(scd_ad);
			vqtr=atoi(third_ad);
			trdx=atoi(fr_ad);
				
			convert_binaire(huit,bin_huit);
			convert_binaire(seize,bin_seize);
			convert_binaire(vqtr,bin_vqtr);
			convert_binaire(trdx,bin_trdx);
				
			sprintf(ad_reseau,"%s%s%s%s",bin_huit,bin_seize,bin_vqtr,bin_trdx);
			
				num++;
				
	}while(strstr(ad_bcast,ad_broadcast) == NULL);
}

void enter_cidr()
{
	char cidr[50];
	char ip_copy[20];
	char *ip;
	char *bits_reseau;
	int i=0;
	int j;
	int error;
	int er=0;
	int compte=0;
	char *one;
	char *two;
	char *three;
	char *four;
	int first;
	int second;
	int third;
	int end;
	int bits;
	
	do
	{
		printf("Entrer l'adresse IP/le nombre de bits de reseau: ");
		scanf("%s",cidr);
		ip=strtok(cidr,"/");
		
		strcpy(ip_copy,ip);
		bits_reseau=strtok(NULL," ");
		j=0;
		er=0;
		i=0;
		compte=0;
		error=0;
		
//-----------------------
		one=strtok(ip_copy,".");
		two=strtok(NULL,".");
		three=strtok(NULL,".");
		four=strtok(NULL,".");
//-----------------------
		
		if(one != NULL && two != NULL && three != NULL && four != NULL)
		{
				first=atoi(one);
				second=atoi(two);
				third=atoi(three);
				end=atoi(four);
				
			if(first > 255 || second > 255 || third > 255 || end >255)
			{
				error=1;
			}
			if(bits_reseau != NULL)
			{
				while(bits_reseau[j] != '\0')
				{
					if(!isdigit(bits_reseau[j]))
					{
						er++;
						break;
					}
					j++;
				}
			
				bits=atoi(bits_reseau);
			}
			if(bits > 32)
			{
				error++;
				
			}
			
			if(ip != NULL)
			{
				while(ip[i] != '\0')
				{
					if(!isdigit(ip[i]))
					{ 
						if(ip[i] == '.')
						{ 
							compte++;
						}
						else
						{ 
							error++;
							break;
						}				
					}
					 i++;				
				}
			}
		}	
	}while(compte != 3 || error != 0 || er != 0 || ip == NULL || bits_reseau == NULL);
	
	
	netmask(bits,ip);
	
	
}

