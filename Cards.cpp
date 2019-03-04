#include "Cards.h"
#include <iostream>

#include "../PowerPlantCard.h"
#include "../SummaryCard.h"
#include "../Step3Card.h"

std::ostream& operator<< (std::ostream &os, const Cards &f) {
	return os << "Details" ;
}
std::ostream& operator<< (std::ostream &os, const PowerPlantCard &f) {
	return os << "This card number is" << f.cardNumber << " max cities supplied is " << f.maxCitiesSupplied << "Resource needed is " << f.nbResourceNeeded << "Resource needed is";
	

}std::ostream& operator<< (std::ostream &os, const SummaryCard &f) {
	return os << "Step one " <<f.one.Details <<f.one.General << "Step two " << f.two.Details << f.two.General << "Step three " << f.three.Details << f.three.General << "Step four " << f.four.Details << f.four.General << "Step five " << f.five.Details << f.five.General
		;
}std::ostream& operator<< (std::ostream &os, const Step3Card &f) {
	return os << "Step3Card";
}