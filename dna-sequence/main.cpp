#include "dna_sequence.h"
#include <iostream>
#include <string>
#include <cstring>


int main()
{
	std::string s("ACTTCTG");
	DnaSequence d1(s);
	DnaSequence d2("ACTTCTG");
	DnaSequence d3 = d2;
	
	std::cout<<"d1: "<<d1<<std::endl;
	std::cout<<"d2: "<<d2<<std::endl;
	std::cout<<"d3: "<<d3<<std::endl;
	std::cout<<"the length: "<<d1.sequenceLength()<<std::endl;
	std::cout<<"print true: "<<(d1 == d2)<<std::endl;
	std::cout<<"d1[0] A: "<<d1[0]<<std::endl;
	d1[1] = 'A';
	std::cout<<"print true: "<<(d1 != d2)<<std::endl;
	std::cout<<"print TTCT: "<< d2.slice(2,6)<<std::endl;
	std::cout<<"print 1: "<< d2.find("CT")<<std::endl;
	std::cout<<"print 2: "<< d2.count("CT")<<": ";
	std::list<size_t> lst = d2.findAll("CT");
	for(std::list<size_t>::iterator i = lst.begin();i!=lst.end();i++)
	{
		std::cout<<*i<< " ";
	}
	std::cout<<std::endl;
	std::cout<<"pair of ACTTCTG : "<< d2.pairing()<<std::endl;
	std::fstream myfile("file.txt");;
	DnaSequence d4(myfile);
	std::cout<<"d4: "<<d4<<std::endl;
	DnaSequence d5("ATGTAGATGTAGTAATGATAATGAATGTAGTAATGA");
	std::cout<<"d5: "<<d5<<" consensus: "<<std::endl;
	std::list<DnaSequence> lst1 = d5.findConsensusSequences();
	for(std::list<DnaSequence>::iterator i = lst1.begin();i!=lst1.end();i++)
	{
		std::cout<<*i<< " ";
	}
	return 0;
}
