#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat {
public:
    
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    void checkGrade(const Bureaucrat& check);
    void setName(std::string value);
    std::string getName() const;
    void setGrade(int value);
    int getGrade() const;
    void increaseGrade();
    void decreaseGrade();

private:
    std::string _name;
    int _grade;
    class GradeTooHighException : public std::exception
    {
        public:
            const char  *what() const noexcept override;
    };
    class GradeTooLowException : public std::exception
    {
        public:
            const char  *what() const noexcept override;
    };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bgrat);

#endif // Bureaucrat_HPP
