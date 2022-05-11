/*totalFee function is used to calculate to total fee from Desa class, tuition class and intl(international) class,
this class use compo
 the operator overloading func in this class will be called in student class,
 */

#ifndef TotelFee_H
#define TotelFee_H
class TotelFee{
    private:
    double desaFee,tuitionfee,internationalfee,totalfee;

    public:
    //default constructoe
    TotelFee(){
        desaFee=0.0;
        tuitionfee=0.0;
        internationalfee=0.0;
        totalfee=0.0;
    }
    

    

};
#endif