#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define MaxIdentifiant 7//le nbr maximum de caracteres de l'identifiant
#define MaxAnne 2021

char NomFichier[]="patient.bin";
char nomf[]="cancer.bin";
char noma[]="avoir.bin";
void mainp(void);
void menupatient(void);
void menucancer(void);
void menuavoir(void);


// declarer structure de date
typedef struct date{
	int j;
	int m;
	int a;
}dat;
//##################################################patient###########################################################
// declarer structure de patient 
typedef struct patient{
	dat date;
	char cin[MaxIdentifiant];
	int num;
	char prenom[20];
	char nom[20];
	char sexe;
	char adresse [20];
    int tel;
	struct patient *suivant;
}patient;
patient* InitListep(patient* l){
    l=NULL;
    return l;
}

// pour verifier le nom 
int ValideNom(char nom[25])
{
    int i = 0;
    while (nom[i])
    {
        if (!((nom[i] >= 'a' && nom[i] <= 'z') || (nom[i] >= 'A' && nom[i] <= 'Z')))
            return -1;

        i++;
        if (i >= 25)
            return -1;
    }
    return 1;
}
int estAnneeBissextile(int annee) {
    return (annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0);
}
//********************************** Verifier la Date *******************************************
int ValideDate(int j, int m, int a) {
    if ((j >= 1) && (j <= 28) && (m >= 1) && (m <= 12) && (a < MaxAnne))
        return 1;
    else if ((j == 29) && (m == 2) && estAnneeBissextile(a)&& (a < MaxAnne))
        return 1;
    else if ((j == 29) && (m != 2) && (a < MaxAnne))
        return 1;
else if ((j == 30) && (m != 2) && (a < MaxAnne))
        return 1;
    else if ((j == 31) && (m != 4) && (m != 6) && (m != 9) && (m != 11) && (a < MaxAnne))
        return 1;
    else
        return -1;
}
//pour saisir la date 
dat SaisieDate(patient *pp)
{
	do
	{
	printf("\n\n\t\t\t\t\t\t\t\t\t Jour:(jj)\t");
	scanf("%d",&pp->date.j);
	}while((pp->date.j<=0)||(pp->date.j>31));
	do
	{
	printf("\n\n\t\t\t\t\t\t\t\t\t Mois:(mm)\t");
	scanf("%d",&pp->date.m);
	}while((pp->date.m<=0)||(pp->date.m>12));
	do
	{
	printf("\n\n\t\t\t\t\t\t\t\t\t Annee:(aaaa)\t");
	scanf("%d",&pp->date.a);
	}while((pp->date.a>=2021));
	return pp->date;
	}
		//**********************************Valide Identifiant************************************

int ValideIdentfiant(char cin[MaxIdentifiant]) {
    // Vérifie la longueur du CIN
    if (strlen(cin) != 7) {
        return -1;
    }

    // Vérifie le format du CIN
    if ((cin[0] != 'P' && cin[0] != 'p')) {
        return -1;
    }
int i;
    // Vérifie les chiffres du CIN
    for ( i = 1; i < MaxIdentifiant; i++) {
        if (!(cin[i] >= '0' && cin[i] <= '9')) {
            return -1;
        }
    }

    return 1; // CIN valide
}
//**************************ajouter un patient**********************************************
patient*InsererTete(patient *l)
{
    patient*nv=(patient*)malloc(sizeof(patient));
    
    // date de naisance
     do
	{
		printf("\n\n\t\t\t\t\t\t\t\t\t la date de naissance de patient(jj-m-aaaa):");
        nv->date=SaisieDate(nv);
        if (ValideDate(nv->date.j,nv->date.m,nv->date.a)==-1)
	    {
		printf("\n\n\t\t\t\t\t\t\t\t\t Date invalide\n");
	
		}
	}while(ValideDate(nv->date.j,nv->date.m,nv->date.a)==-1);
		// ajouter le cin
		
		// ajouter le cin
	
	if (nv->date.a< 2003){
		debut:
	printf("\n\n\t\t\t\t\t\t\t\t\t cin :\t \t\t\t\t\t");
	do
	{
	scanf("%s",&nv->cin);
	if(ValideIdentfiant(nv->cin)==-1)
		printf("\n\n\t\t\t\t\t\t\t\t\t\aIDENTIFIANT NON VALIDE\nVEUILLEZ ENTRER UN IDENTIFIANNT DE LA FORME P000000:\t");

	}while (ValideIdentfiant(nv->cin)==-1);
	 
    patient* t;
    t=l;
    while(t!=NULL){
       if(t->cin==nv->cin){
           printf("\n\n\t\t\t\t\t\t\t\t\t il existe déja\n");
           goto debut;
         
       }
       t=t->suivant;
    }
	}
	else 
	{ strcpy(nv->cin, "p000000");

	
		
}
    	// ajouter le numero de patient 
	
	deb:
	printf("\n\n\t\t\t\t\t\t\t\t\t numero de patient :\t\t");
	scanf ("%d",&nv->num);
	 patient* tm;
    tm=l;
    while(tm!=NULL){
       if(tm->num==nv->num){
           printf("\n\n\t\t\t\t\t\t\t\t\t cette numero de patient existe deja, donner une autre\n");
           goto deb;
       }
       tm=tm->suivant;
    }
    	// ajouter le nom de patient 
	do
	{
	printf("\n\n\t\t\t\t\t\t\t\t\t Nom:\t\t\t\t\t");
	scanf("%s",&nv->nom);
	if(ValideNom(nv->nom)==-1) 
		printf("\n\n\t\t\t\t\t\t\t\t\t NOM INVALIDE\a\n");
	}while(ValideNom(nv->nom)==-1);
  	//ajouter le prenom
	do
	{
	printf("\n\n\t\t\t\t\t\t\t\t\t Prenom:\t\t\t\t\t");
	scanf("%s",&nv->prenom);
	if(ValideNom(nv->prenom)==-1) 
		printf("\tPRENOM INVALIDE\a\n");
	}while(ValideNom(nv->prenom)==-1);
	// ajouter sexe
	printf("\n\n\t\t\t\t\t\t\t\t\tSexe (M:male/F:female):\t\t\t\t\t");
            do{
		
	scanf("%c",&nv->sexe);
}while((nv->sexe !='f') &&(nv->sexe !='F') &&(nv->sexe !='m') && (nv->sexe !='M') );

// ajouter adresse 
printf ("\n\n\t\t\t\t\t\t\t\t\t ville\t\t\t:\t");
scanf("%s",&nv->adresse);

	
	

// ajouter telephone 
 printf ("\n\n\t\t\t\t\t\t\t\t\t tel\t\t\t\t:\t");
scanf("%d",&nv->tel);
 
    
 nv->suivant=l;
return nv ;




}
//**************************afficher patient**********************************************

void afficher_tout(patient*l){

    patient *tmp;
    tmp=l;
    if(tmp==NULL){
        printf("\n\n\t\t\t\t\t\t\tLa liste des produits est vide\n");
    }          
    
    while(tmp!=NULL){
    	 printf("\ndate de naissance:%d/%d/%d",tmp->date.j,tmp->date.m,tmp->date.a);
		printf("\tnom : %s\t\tprenom : %s\t",tmp->nom,tmp->prenom);
        printf("numero :%d\t",tmp->num);
        printf("CIN :%s\t",tmp->cin);
        printf("sexe:%c\t",tmp->sexe);
        printf("adresse :%s\t",tmp->adresse);
        printf("telephone :0%d\n",tmp->tel);
        tmp=tmp->suivant;
    }
}
//**************************rechercher patient**********************************************
void rechercher(patient* l) {
    int a;
    printf("\n\n\t\t\t\t\t\t\tEntrez le numero du patient a rechercher : ");
    scanf("%d", &a);

    patient* tmp = l;
    while (tmp != NULL && tmp->num != a) {
        tmp = tmp->suivant;
    }

    if (tmp == NULL) {
        printf("\n\n\t\t\t\t\t\t\tCe numero de patient n'existe pas.\n");
    } else {
        printf("\n\n\t\t\t\t\t\t\tNuméro : %d\n", tmp->num);
        printf("\n\n\t\t\t\t\t\t\tCIN : %s\n", tmp->cin);
        printf("\n\n\t\t\t\t\t\t\tNom : %s\n", tmp->nom);
        printf("\n\n\t\t\t\t\t\t\tPrénom : %s\n", tmp->prenom);
        printf("\n\n\t\t\t\t\t\t\tDate de naissance : %d-%d-%d\n", tmp->date.j, tmp->date.m, tmp->date.a);
        printf("\n\n\t\t\t\t\t\t\tSexe : %c\n", tmp->sexe);
        printf("\n\n\t\t\t\t\t\t\tville : %s\n", tmp->adresse);
        printf("\n\n\t\t\t\t\t\t\tTelephone : 0%d\n", tmp->tel);
    }
}

//**************************sauvgarder patient**********************************************
void sauvegarder(patient *l){ 
FILE*f;
 // si liste non vide
 if(l!=NULL){
 //ouvrir un fichier binaire en Ã©criture : suffixe b
 if((f=fopen("al.bin","wb"))!=NULL){
 // parcourir la liste jusque fin
 while(l!=NULL){
 fwrite(l,sizeof(patient),1,f); // copier chaque patient
 l=l->suivant; // passer au patient suivant
 }
 fclose(f); // fermer le fichier
 }
 else
printf("erreur crÃ©ation fichier\n");
 }
 else
 printf("na peux pas de sauvegarde pour une liste vide\n");
 int sup=remove("patient.bin");
 int ren =rename("al.bin","patient.bin");
 
}


//**************************modifier les informations d'un patient**********************************************
patient *Modifierp(patient *p) {
    patient *tmp = p;
    int n;
    printf("\n\n\t\t\t\t\t\t\t\tDonner le numero du patient pour modifier ses informations:");
    scanf("%d", &n);

    while (tmp != NULL) {
        if (tmp->num == n) {
            printf("\nle patient existe dans la liste....");

           
		   date: // Nouvelle date de naissance
            printf("donner la nouvelle date de naissance:\n");
            tmp->date=SaisieDate(tmp);

            // Validation de la date
            if (ValideDate(tmp->date.j, tmp->date.m, tmp->date.a) == -1) {
                printf("Date invalide\n");
                goto date;
                
            }

            // Nouveau CIN (si la date de naissance est avant 2003)
            if (tmp->date.a < 2003) {
            	cin:
                printf("cin:");
                scanf("%s", tmp->cin);

                // Validation du CIN
                if (ValideIdentfiant(tmp->cin) == -1) {
                    printf("CIN invalide\n");
                goto cin;
                }
            }

            // Nouveau nom
          name:  printf("nom:");
            scanf("%s", tmp->nom);

            // Validation du nom
            if (ValideNom(tmp->nom) == -1) {
                printf("Nom invalide\n");
                goto name;
                return p; // Stop the modification if the nom is invalid
            }

            // Nouveau prénom
            prenom:
            printf("prenom:");
            scanf("%s", tmp->prenom);

            // Validation du prénom
            if (ValideNom(tmp->prenom) == -1) {
                printf("Prenom invalide\n");
                goto prenom;
                return p; // Stop the modification if the prénom is invalid
            }

            // Adresse, téléphone, etc. - à compléter selon les besoins
            	printf("Sexe (M:male/F:female):\t");
            do{
		
	scanf("%c",&tmp->sexe);
}while((tmp->sexe !='f') &&(tmp->sexe !='F') &&(tmp->sexe !='m') && (tmp->sexe !='M') );

	
// ajouter adresse 
printf (" ville\t\t\t:\t");
scanf("%s",&tmp->adresse);

	
	

// ajouter telephone 
 printf ("\n tel\t\t\t\t:\t");
scanf("%d",&tmp->tel);
 

            printf("\nModification des informations réussie!\n");
            return p;
        }
        tmp = tmp->suivant;
    }
    printf("\n\t\t\t\t\t\t\t\tPatient n'existe pas\n");
    return p;
}

 // *********************************telecharger
patient* load_liste() {
    FILE* f;
    patient* prem = NULL, *p, e;

    if ((f = fopen("patient.bin", "rb")) != NULL) {
        fread(&e, sizeof(patient), 1, f);
        prem = malloc(sizeof(patient));
        *prem = e;
        p = prem;

        while (fread(&e, sizeof(patient), 1, f)) {
            p->suivant = malloc(sizeof(patient));
            p = p->suivant;
            *p = e;
            p->suivant = NULL;
        }

        fclose(f);
    } 

    return prem;
}

//********************************supprimer
patient* supprimer(patient *l){
    int a;
    if(l==NULL)
        return l;
    printf( "\n\n\t\t\t\t\t\t\tentrez le numero du patient que vous voulez supprimer: ");
    scanf("%d",&a);
    patient*  tmp =l;
    while(tmp!=NULL){
        if(tmp->num==a){
            printf("\n\n\t\t\t\t\t\t\t Ce patient va etre supprime\n");
            if(tmp==l)
                 l=l->suivant;
            else{
                patient*tmp2=l;
                while(tmp2->suivant!=tmp)
                     tmp2=tmp2->suivant;
                tmp2->suivant=tmp->suivant;
                free(tmp);
                }
                return l;
        }
        tmp=tmp->suivant;
    }
    if(tmp==NULL){
        printf("\n\n\t\t\t\t\t\t\tla reference que vous avez donne n'existe pas\n");
        return l;
    }
    printf("\n\n\t\t\t\t\t\t\til n'y a aucun patient a supprimer, vous devez ajouter un\n");
    return l;
}

//################################################cancer##############################################
//declaration de la structure cancer
typedef struct cancer{
	int ID;
	char nom[39];
	struct cancer *suivant;
}cancer;
cancer* InitListe(cancer* c){
c=NULL;
return c;
}
//**************************ajouter un cancer**********************************************
cancer*Insererc(cancer *c){
    
    cancer*nv=(cancer*)malloc(sizeof(cancer));
    	// ajouter l'ID du cancer 
    	cancer:
	printf("\n\n\t\t\t\t\t\t\t\t\tid:");
	scanf ("%d",&nv->ID);
	cancer* tm;
    tm=c;
    while(tm!=NULL){
       if(tm->ID==nv->ID){
           printf("\n\t\t\t\t\t\t\t\t cet ID existe deja, donner un autre\n");
           goto cancer;
       }
       tm=tm->suivant;
    }
    	// ajouter le nom du cancer 
	do
	{
	printf("\n\n\t\t\t\t\t\t\t\t\t Nom:\t");
	scanf("%s",&nv->nom);
	if(ValideNom(nv->nom)==-1) 
		printf("\n\n\t\t\t\t\t\t\t\t\t NOM INVALIDE\a\n");
	}while(ValideNom(nv->nom)==-1);
    nv->suivant=c;
    return nv ;
  
}
//**************************afficher les types de cancer**********************************************
void afficherc(cancer*c){
    cancer *tmp;
    tmp=c;
    if(tmp==NULL){
	    printf("\n\n\t\t\t\t\t\t\tLa liste  de cancer est vide\n");
    }
    while(tmp!=NULL){    
	   printf("\n\t\t\t\t\tID:%d\t",tmp->ID);    
		printf("\t\t\t\t\tNOM:%s\t\n",tmp->nom);
       
        tmp=tmp->suivant;
    }
}
//**************************rechercher les types de cancer**********************************************
void rechercherc(cancer*c){
    int a;
    printf("\n\n\t\t\t\t\t\t\tentrez l'ID du type de cancer a rechercher ");
    scanf("%d",&a);
    cancer*tmp=c;
    while(tmp->ID!=a){
        tmp=tmp->suivant;
        if(tmp==NULL){
            printf("\n\n\t\t\t\t\t\t\t\t\t\tce numero n'existe pas \n ");
            return ;
        }
    }
    printf("\n\n\t\t\t\t\t\t\tID:%d\n",tmp->ID);
    printf("\n\n\t\t\t\t\t\t\tnom:%s\n",tmp->nom);
}
//**************************supprimer un type**********************************************
cancer* supprimerc(cancer *c){
    int a;
    if(c==NULL)
        return c;
    printf( "\n\n\t\t\t\t\t\t\tentrez l'ID du type que vous voulez supprimer ");
    scanf("%d",&a);
    cancer*  tmp =c;
    while(tmp!=NULL){
        if(tmp->ID==a){
            printf("\n\n\t\t\t\t\t\t\t Ce type va etre supprime\n");
            if(tmp==c)
                 c=c->suivant;
            else{
                cancer*tmp2=c;
  while(tmp2->suivant!=tmp)
                     tmp2=tmp2->suivant;
                tmp2->suivant=tmp->suivant;
                free(tmp);
                }
                return c;
        }
        tmp=tmp->suivant;
    }
    if(tmp==NULL){
        printf("\n\n\t\t\t\t\t\t\tla reference que vous avez donne n'existe pas\n");
        return c;
    }
    printf("\n\n\t\t\t\t\t\t\til n'y a aucun type a supprimer, vous devez ajouter un\n");
    return c;
}
//**************************modifier un type**********************************************
cancer *Modifierc(cancer *c){
    cancer *tmp=c;
    int n;
    printf("\n\t\t\t\t\t\t\tDonner le numero du type pour modifier ses informations:");
    scanf("%d",&n);
    while(tmp!=NULL){
        if(tmp->ID==n){
        	
            printf("\n\t\t\t\t\t\t\tle type existe dans la liste....");
            d:
            printf("\n\t\t\t\t\t\t\t\t\tNOM:");
            scanf("%s",&tmp->nom);
           if(ValideNom(tmp->nom)==-1) goto d;
            return c;
        }
        tmp=tmp->suivant;
    }
   printf("\n\t\t\t\t\t\t\t\t\tce type n'existe pas\n"); 
	} 
     
//****************************sauvgarder******************************
void sauvegarderc(cancer *c){ 
FILE*p;
 // si liste non vide
 if(c!=NULL){
 //ouvrir un fichier binaire en Ã©criture : suffixe b
 if((p=fopen("can.bin","wb"))!=NULL){
 // parcourir la liste jusque fin
 while(c!=NULL){
 fwrite(c,sizeof(cancer),1,p); // copier chaque patient
 c=c->suivant; // passer au patient suivant
 }
 fclose(p); // fermer le fichier
 }
 else
printf("erreur crÃ©ation fichier\n");
 }
 else
 printf("na peux pas de sauvegarde pour une liste vide\n");
 int supp=remove("cancer.bin");
 int renp =rename("can.bin","cancer.bin");
 
}
// *********************************telecharger********************************
 cancer* load_listec()
{
FILE*p;
cancer*prem=NULL,*x,e;
 if((p=fopen("cancer.bin","rb"))!=NULL){
 prem=malloc(sizeof(cancer));
 fread(prem,sizeof(cancer),1,p);
 x=prem;
 while(fread(&e,sizeof(cancer),1,p)){
 x->suivant=malloc(sizeof(cancer));
 x=x->suivant;
 *x=e;
 x->suivant=NULL;
 }
 fclose(p);
 }
 
 return prem;
}
//##################################################avoir cancer##############################
//declaration de la structure avoir
typedef struct avoir{
	int ID;
	int num;
	dat date;
	struct avoir *suivant;
}avoir;
avoir* InitListea(avoir* a){
a=NULL;
return a;
}
//**************************ajouter**********************************************
dat SaisieDatea(avoir *pp)
{
	do
	{
	printf("\n\t\t\t\t\t\t\tJour:(jj)\t");
	scanf("%d",&pp->date.j);
	}while((pp->date.j<=0)||(pp->date.j>31));
	do
	{
	printf("\n\t\t\t\t\t\t\tMois:(mm)\t");
	scanf("%d",&pp->date.m);
	}while((pp->date.m<=0)||(pp->date.m>12));
	do
	{
	printf("\n\t\t\t\t\t\t\tAnnee:(aaaa)\t");
	scanf("%d",&pp->date.a);
	}while((pp->date.a>=2021));
	return pp->date;
	}
avoir*Inserera(avoir *l , cancer *c, patient *a ){
    FILE *p=fopen("avoir.txt","a");
    avoir*nv=(avoir*)malloc(sizeof(avoir));
    // ajouter l'ID
    
   // Ajouter l'ID du cancer
    cancer *tmCancer = c;
    int cancerExiste = 0;
    printf("\n\n\t\t\t\t\t\t\tID du type du cancer\t\t:");
    scanf("%d", &nv->ID);

   while (tmCancer != NULL) {
   
    if (tmCancer->ID == nv->ID) {
      
        cancerExiste = 1;  // Mettez la variable à 1 pour indiquer que l'ID a été trouvé
        break;
    }
    tmCancer = tmCancer->suivant;
}


    if (!cancerExiste) {
    printf("\n\t\t\t\t\t\t\tCe type de cancer avec l'ID %d n'existe pas dans notre base.\n", nv->ID);
    free(nv);
    fclose(p);
    return l;
}

    // Ajouter le numéro de patient
    patient *tmpPatient = a;
    printf("\n\n\t\t\t\t\t\t\tnumero de patient \t\t:");
    scanf("%d", &nv->num);

    // Vérifier si le patient existe
    while (tmpPatient != NULL) {
        if (tmpPatient->num == nv->num) {
            break;
        }
        tmpPatient = tmpPatient->suivant;
    }

    if (tmpPatient == NULL) {
        printf("\n\t\t\t\t\t\t\tCe patient n'existe pas dans notre base, impossible d'ajouter.\n");
       
        return l;
    }

    //date d'atteinte du cancer
    
    
     do
	{
		printf("\n\n\t\t\t\t\t\t\t\t\t la date d'avoir le cancer (jj-m-aaaa):");
        nv->date=SaisieDatea(nv);
        if (ValideDate(nv->date.j,nv->date.m,nv->date.a)==-1)
	    {
		printf("\n\n\t\t\t\t\t\t\t\t\t Date invalide\n");
	
		}
	}while(ValideDate(nv->date.j,nv->date.m,nv->date.a)==-1);
    nv->suivant=l;
    return nv ;
}//**************************afficher**********************************************
void affichera(avoir*l){
	
    avoir *tmp;
    tmp=l;

    if(tmp==NULL){
	    printf("\n\n\t\t\t\t\t\t\tLa liste est vide\n");
    }
    while(tmp!=NULL){        
		printf("\n num de patient :%d\t",tmp->num);
        printf("ID de cancer:%d\t",tmp->ID);
        printf("\tdate de maladie :%d-%d-%d\n",tmp->date.j,tmp->date.m,tmp->date.a);
        tmp=tmp->suivant;
    }
}
//**************************rechercher**********************************************
void recherchera(avoir *l) {
    int a;
    printf("\n\n\t\t\t\t\t\t\tentrez le numero du patient a rechercher ");
    scanf("%d", &a);
    avoir *tmp = l;
    int patientTrouve = 0;  // Ajoutez une variable pour suivre si le patient est trouvé

    while (tmp != NULL) {
        if (tmp->num == a) {
            printf("\tnum:%d\n", tmp->num);
            printf("\tID:%d\n", tmp->ID);
            printf("\tdate de maladie:%d-%d-%d\n", tmp->date.j, tmp->date.m, tmp->date.a);
            // Ajoutez ici l'affichage des autres informations liées au cancer
            patientTrouve = 1;  // Indique que le patient a été trouvé
        }
        tmp = tmp->suivant;
    }

    // Ajoutez un message si le patient n'est pas trouvé après la boucle
    if (!patientTrouve) {
        printf("\n\n\t\t\t\t\t\t\t\t\t\tCe numero n'existe pas.\n");
    }
}

//**************************supprimer**********************************************
avoir* supprimera(avoir *l){
    int a;
    if(l==NULL)
        return l;
    printf( "\n\n\t\t\t\t\t\t\tentrez le numero du patient que vous voulez supprimer ");
    scanf("%d",&a);
    avoir*  tmp =l;
    while(tmp!=NULL){
        if(tmp->num==a){
            printf("\n\n\t\t\t\t\t\t\t Ce type va etre supprimer\n");
            if(tmp==l)
                 l=l->suivant;
            else{
                avoir*tmp2=l;
                while(tmp2->suivant!=tmp)
                     tmp2=tmp2->suivant;
                tmp2->suivant=tmp->suivant;
                free(tmp);
                }
                return l;
        }
        tmp=tmp->suivant;
    }
    if(tmp==NULL){
        printf("\n\n\t\t\t\t\t\t\tla reference que vous avez donne n'existe pas\n");
        return l;
    }
    printf("\n\n\t\t\t\t\t\t\til n'y a rien a supprimer, vous devez ajouter\n");
    return l;
}
//**************************modifier**********************************************
avoir *Modifiera(avoir *a,cancer *c){
    avoir *tmp=a;
    avoir*nv=(avoir*)malloc(sizeof(avoir));

    int n;
    printf("\n\t\t\t\t\t\t\t\t\t\tDonner le numero du patient pour modifier ses informations:");
    scanf("%d", &n);

    while (tmp != NULL) {
        if (tmp->num == n) {
            printf("\n\n\n\t\t\t\t\t\t\tle patient existe dans la liste....");

            // Modifier l'ID du cancer
            cancer *tmCancer = c;
            int cancerExiste = 0;
            printf("\n\n\n\t\t\t\t\t\t\tdonner le nouveau ID de concer:");
            scanf("%d", &tmp->ID);

            while (tmCancer != NULL) {
                if (tmCancer->ID == tmp->ID) {
                    printf("\n\n\t\t\t\t\t\t\tCancer trouvé\t\t:");
                    cancerExiste = 1;
                    break;
                }
                tmCancer = tmCancer->suivant;
            }

            if (!cancerExiste) {
                printf("\n\t\t\t\t\t\t\tCe type de cancer avec l'ID %d n'existe pas dans notre base.\n", tmp->ID);
               
                return a;
            }

           
        do{
		printf("\n\n\n\t\t\t\t\t\t\tdonner la nouvelle date d'atteinte du cancer(jj-m-aaaa):");
        nv->date=SaisieDatea(nv);
        if (ValideDate(nv->date.j,nv->date.m,nv->date.a)==-1)
	    {
		    printf("\n\t\t\t\t\t\t\t\tDate invalide\n");
	    }
	    }while(ValideDate(nv->date.j,nv->date.m,nv->date.a)==-1);
            return a;
        }
        tmp=tmp->suivant;
    }
    printf("\n\t\t\t\t\t\t\t\t\tn'existe pas\n");     
}
//****************************sauvgarder******************************
void sauvegardera(avoir *a){ 
FILE*t;
 // si liste non vide
 if(a!=NULL){
 //ouvrir un fichier binaire en Ã©criture : suffixe b
 if((t=fopen("cav.bin","wb"))!=NULL){
 // parcourir la liste jusque fin
 while(a!=NULL){
 fwrite(a,sizeof(avoir),1,t); // copier chaque patient
 a=a->suivant; // passer au patient suivant
 }
 fclose(t); // fermer le fichier
 }
 else
printf("erreur crÃ©ation fichier\n");
 }
 else
 printf("na peux pas de sauvegarde pour une liste vide\n");
 int supa=remove("avoir.bin");
 int rena =rename("cav.bin","avoir.bin");
 
}
// *********************************telecharger********************************
 avoir* load_listea()
{
FILE*t;
avoir*prem=NULL,*x,e;
 if((t=fopen("avoir.bin","rb"))!=NULL){
 prem=malloc(sizeof(avoir));
 fread(prem,sizeof(avoir),1,t);
 x=prem;
 while(fread(&e,sizeof(avoir),1,t)){
 x->suivant=malloc(sizeof(avoir));
 x=x->suivant;
 *x=e;
 x->suivant=NULL;
 }
 fclose(t);
 }
 
 return prem;
}


 // pour afficher le premier page d'acceuil
void welcome()
{printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t**************************************************");
printf("\n\t\t\t\t\t\t\t\t**\t\t\tbienvenue \t\t**");
printf("\n\t\t\t\t\t\t\t\t**\t\t a la fondation Benis \t\t**");
printf("\n\t\t\t\t\t\t\t\t**\t  prevention et traitement des cancers \t**");
printf("\n\t\t\t\t\t\t\t\t**************************************************");
printf("\n\n\n\n\n\n\n\n appuyez sur n'importe quel bouton pour suivez......\n");
 getch();
system("cls");
}
// pour afficher le titre de fondation 
void titre()
{printf("\n\n\t\t\t\t\t\t\t\t----------------------------------------------------------------");
printf("\n\n\t\t\t\t\t\t\t\t\t\t\t fondation benis");
printf("\n\n\t\t\t\t\t\t\t\t----------------------------------------------------------------");
}
// pour entrez a le programme
void login()
{char nom[20];
char pas [15];
char nomoriginal[20]="benis";
char pasoriginal [15]="vie2021";
do {
printf ("\n\n\n\n\t\t\t\t\t\t\t\t\t\t entrez votre nom et mot de passe: ");
printf ("\n\n\n\t\t\t\t\t\t\t\t\t\t\t nom\t\t: ");
scanf("%s",&nom);
printf ("\n\n\n\t\t\t\t\t\t\t\t\t\t\t mot de passe   : ");
scanf("%s",&pas);
if(strcmp(nom,nomoriginal)==0&&strcmp(pas,pasoriginal)==0)
{printf("\n\n\n\t\t\t\t \t\tacces reussie...");
getch();
mainp();
break;
}
else
{

printf ("\n\t\t\t\t votre nom ou bien mot de passe est incorrecte (essayez autre fois)");
 getch();
system("cls");
titre();}

}while(strcmp(nom,nomoriginal)!=0&&strcmp(pas,pasoriginal)!=0);
}
// main1
main ()
{welcome();
titre();
login();
}
void mainp(void){
	int choix;
	do{
	
	system("cls");
    titre();
    
    printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t 1-patient");
    printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t 2-cancer");
    printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t 3-avoir cancer");
    printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t 4- QUITTER");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tchoisissez de 1 a 4:");
    scanf("%d",&choix);
    switch(choix){
	    case 1: menupatient();
	    break;
	    case 2: menucancer();break;
	    case 3: menuavoir();break;
        case 4: break;	
    }
}while (choix != 4);
}
void menupatient(void) {
    int choix;
    patient *l;
    
    do {
        system("cls");
        titre();

        l = InitListep(l);
        l = load_liste();

        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t 1-ajouter un patient");
        printf("\n\n\t\t\t\t\t\t\t\t\t 2-afficher les patients");
        printf("\n\n\t\t\t\t\t\t\t\t\t 3-rechercher dans le dossier d'un patient");
        printf("\n\n\t\t\t\t\t\t\t\t\t 4-supprimer un patient");
        printf("\n\n\t\t\t\t\t\t\t\t\t 5-modifier dans le dossier d'un patient");
        printf("\n\n\t\t\t\t\t\t\t\t\t 6-quitter le menu");
        printf("\n\n\t\t\t\t\t\t\t\t\t 7-retour au menu principal");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tchoisissez de 1 a 7:");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                system("cls");
                titre();
                printf("\n\t\t\t\t\t\t\t\t\t\tajouter un patient:");
                l = InsererTete(l);
                sauvegarder(l);
                printf("\n\n\t\t\t\t\t\t\t\t\tfrapper une touche pour retourner aux MENU");
                getch();
                break;
            case 2:
                system("cls");
                titre();
                printf("\n\t\t\t\t\t\t\t\t\t\tafficher les patients:");
                l = load_liste();
                afficher_tout(l);
                printf("\n\n\t\t\t\t\t\t\t\t\tfrapper une touche pour retourner aux MENU");
                getch();
                break;
            case 3:
                system("cls");
                titre();
                printf("\n\t\t\t\t\t\t\t\t\t\tchercher un patient:");
                l = load_liste();
                rechercher(l);
                printf("\n\n\t\t\t\t\t\t\t\t\tfrapper une touche pour retourner aux MENU");
                getch();
                break;
            case 4:
                system("cls");
                titre();
                printf("\n\t\t\t\t\t\t\t\t\t\tsupprimer un patient:");
                l = supprimer(l);
                sauvegarder(l);
                printf("\n\n\t\t\t\t\t\t\t\t\tfrapper une touche pour retourner aux MENU");
                getch();
                break;
            case 5:
                system("cls");
                titre();
                printf("\n\t\t\t\t\t\t\t\t\t\tmodifier les informations d'un patient:");
                l = Modifierp(l);
                sauvegarder(l);
                printf("\n\n\t\t\t\t\t\t\t\t\tfrapper une touche pour retourner aux MENU");
                getch();
                break;
            case 6:
                system("cls");
                titre();
                printf("\n\n\t\t\t\t\t\t\t\t\tquitter le programme");
                getch();
                break;
            case 7:
                system("cls");
                titre();
                printf("\n\n\t\t\t\t\t\t\t\t\tretour au menu principal");
                printf("\n\n\t\t\t\t\t\t\t\t\tfrapper une touche pour retourner aux MENU");
                getch();
                break;
        }
    } while (choix != 6 && choix != 7);

    if (choix == 7) {
        mainp();
    }
}
void menucancer(void){
 
	int choix;
	 cancer *c;
	 
	do{	system("cls");
	titre();

	
   
c=InitListe(c);
c=load_listec();
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t 1-ajouter un type de cancer");
    printf("\n\n\t\t\t\t\t\t\t\t\t 2-afficher les types de cancer");
    printf("\n\n\t\t\t\t\t\t\t\t\t 3-chercher un type de cancer");
    printf("\n\n\t\t\t\t\t\t\t\t\t 4-supprimer  un type de cancer");
    printf("\n\n\t\t\t\t\t\t\t\t\t 5-modifier un type de cancer ");
  
    printf("\n\n\t\t\t\t\t\t\t\t\t 6-quitter le programme");
    printf("\n\n\t\t\t\t\t\t\t\t\t 7-retour au menu principal");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tchoisissez de 1 a 7:");
    scanf("%d",&choix);
	switch(choix){
	    case 1: system("cls");
		        titre();
		        printf("\n\n\t\t\t\t\t\t\t\t\t ajouter un type de cancer");
		        c=Insererc(c);
		        sauvegarderc(c);
				printf("frapper une touche pour retourner aux MENU");
			    getch();
              break;
		case 2:	system("cls");
		        titre();
		        printf("\n\n\t\t\t\t\t\t\t\t\t afficher les types de cancer\n\n");
		        c=load_listec();
		        afficherc(c);
		        printf("frapper une touche pour retourner aux MENU");
				getch();
			 break;
		case 3: system("cls");
		        titre();
		        printf("\n\n\t\t\t\t\t\t\t\t\t chercher un type de cancer\n\n");
		        c=load_listec();
		        rechercherc(c);
	            printf("frapper une touche pour retourner aux MENU");
				getch();
			 break;
		case 4:	system("cls");
		        titre();
		        printf("\n\n\t\t\t\t\t\t\t\t\t supprimer  un type de cancer\n\n");
		        c=supprimerc(c);
		        sauvegarderc(c);
	            printf("frapper une touche pour retourner aux MENU");
				getch();
				 break;
        case 5: system("cls");
		        titre();
		        printf("\n\n\t\t\t\t\t\t\t\t\t modifier un type de cancer\n\n ");
		        c=Modifierc(c);
		        sauvegarderc(c);
		        printf("frapper une touche pour retourner aux MENU");
				getch();
			    break;
				
		case 6: system("cls");
		        titre();
		        printf("\n\n\t\t\t\t\t\t\t\t\tquitter le programme");
				getch();
				break;
		case 7: system("cls");
		        titre();
		        printf("\n\n\t\t\t\t\t\t\t\t\tretour au menu principal");
	            printf("frapper une touche pour retourner aux MENU");
				getch();
	          break;	}		        
    } while (choix != 6 && choix != 7);
    if (choix ==7){
		mainp();
}
}

void menuavoir(void){
	int choix;
	avoir *a;
	 cancer *c;
	 patient *l;
	
	do{
	
	system("cls");
    titre();
    c=InitListe(c);

   a=InitListea(a);
   a=load_listea();
     l = InitListep(l);
      
    printf("\n\n\t\t\t\t\t\t\t\t\t 1-ajouter");
    printf("\n\n\t\t\t\t\t\t\t\t\t 2-afficher");
    printf("\n\n\t\t\t\t\t\t\t\t\t 3-rechercher");
    printf("\n\n\t\t\t\t\t\t\t\t\t 4-supprimer");
    printf("\n\n\t\t\t\t\t\t\t\t\t 5-modifier");
   printf("\n\n\t\t\t\t\t\t\t\t\t 6-quitter le menu");
    printf("\n\n\t\t\t\t\t\t\t\t\t 7-retour au menu principal");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tchoisissez de 1 a 7:");
    scanf("%d",&choix);
	switch(choix){
		case 1 :system("cls");
		        titre();
		        printf("\n\t\t\t\t\t\t\t\t\t\tajouter:");
		        c=load_listec();
		          l = load_liste();
		        a=Inserera(a,c,l);
		        sauvegardera(a);
				printf("frapper une touche pour retourner aux MENU");
			    getch();
			    break;
		case 2:	system("cls");
		        titre();
		        printf("\n\t\t\t\t\t\t\t\t\t\tafficher:");
		        a=load_listea();
		        affichera(a);
		        printf("frapper une touche pour retourner aux MENU");
				getch();
				  break;				
		case 3: system("cls");
		        titre();
		        printf("\n\t\t\t\t\t\t\t\t\t\tchercher:");
		        a=load_listea();
		        recherchera(a);
	            printf("frapper une touche pour retourner aux MENU");
				getch();
			  break;
		case 4:	system("cls");
		        titre();
		        printf("\n\t\t\t\t\t\t\t\t\t\tsupprimer:");
		        a=supprimera(a);
		        sauvegardera(a);
	            printf("frapper une touche pour retourner aux MENU");
				getch();
		        break;
	    case 5: system("cls");
		        titre();
		        printf("\n\t\t\t\t\t\t\t\t\t\tmodifier les informetions:");
		         c=load_listec();
		        a=Modifiera(a,c);
		        sauvegardera(a);
	            printf("frapper une touche pour retourner aux MENU");
				getch();
		         break;
	  
		case 6:system("cls");
		        titre();
		        printf("\n\n\t\t\t\t\t\t\t\t\tquitter le programme");
				getch();
				break;
		case 7: system("cls");
		        titre();
		        printf("\n\n\t\t\t\t\t\t\t\t\tretour au menu principal");
	            printf("frapper une touche pour retourner aux MENU");
				getch();
				break;		 
    }
} while (choix != 6 && choix != 7);
    if (choix ==7){
		mainp();
}
}

