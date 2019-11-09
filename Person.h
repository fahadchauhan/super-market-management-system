#ifndef PERSON_H
#define PERSON_H

class Person{
	private:		
		int age;
		char * name;
		char * gender;
	public:
		Person();
		Person( int, char*, char* );
		~Person();
//			Setter Functions
		void setAge( int );
		void setName( char* );
		void setGender( char* );
//			Getter Functions
		int getAge() const;
		char * getName() const;
		char * getGender() const;
//			Other Functions
		virtual void display() const = 0;
};

#endif
