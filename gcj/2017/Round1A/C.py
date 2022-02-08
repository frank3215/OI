Hd=11 #Your HP
Ad=5 #Your ATK
Hk=16 #Knight's HP
Ak=5 #Knight's ATK
B=0 #Buff +ATK
D=0 #Debuff -ATK
Rd=(Hk-1)/Ad+1 #Remaining rounds needed to defeat the knight
Rk=(Hd-1)/Ak+1 #Dead in
#IMPOSSIBLE: Knight defeats you in less than three rounds
#Cure:Only if you're going to die and Rk > 1 this round
#Debuff:If Ak=1 and  or 
#Buff:If R <= (Hk-1/Ak)
