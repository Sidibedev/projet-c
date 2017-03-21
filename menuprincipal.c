

// l'interface qui permet a l'utilisateur de choisir ce qu'il veut faire.
PTR supprimer(char *mot,PTR L)
	{
		PTR L1,L2,L3;
		if(L==NULL)
			return L;
		else
			{
				L1=L;
				L2=L1->suiv;
				while(L2!=NULL && L2->mot!=mot)
					{
                          L1=L2;
						L2=L2->suiv;
					    }
				if(L2->mot==mot)
					{
						L1->suiv=L2->suiv;
						L2->suiv=NULL;
						free(L2);
					}
				return L;
			}
	}
