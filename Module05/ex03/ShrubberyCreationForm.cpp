#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <stdexcept>

static void DrawTree( std::fstream &file )
{
   file << "          . . .                                  \n"
        << "        .        .  .     ..    .                \n"
        << "     .                 .         .  .            \n"
        << "                     .                           \n"
        << "                    .                ..          \n"
        << "    .          .            .              .     \n"
        << "    .            '.,        .               .    \n"
        << "    .              'b      *                     \n"
        << "     .              '$    #.                ..   \n"
        << "    .    .           $:   #:               .     \n"
        << "  ..      .  ..      *#  @):        .   . .      \n"
        << "               .     :@,@):   ,.**:'   .         \n"
        << "   .      .,         :@@*: ..**'      .   .      \n"
        << "            '#o.    .:(@'.@*''  .                \n"
        << "    .  .       'bq,..:,@@*'   ,*      .  .       \n"
        << "               ,p$q8,:@)'  .p*'      .           \n"
        << "        .     '  . '@@Pp@@*'    .  .             \n"
        << "         .  . ..    Y7'.'     .  .               \n"
        << "                   :@):.                         \n"
        << "                  .:@:'.                         \n";
}

static void openFile( const std::string &target, std::fstream &file )
{
   std::string openPath = target + "_shrubbery";

   file.open( openPath.c_str(), std::fstream::trunc | std::fstream::out );
   if ( !file )
      throw std::runtime_error( openPath + ": File not inaccessible" );
}

ShrubberyCreationForm::ShrubberyCreationForm( void )
  : AForm::AForm( "ShrubberyCreationForm", 145, 137 )
{
   _target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string &target )
  : AForm::AForm( "ShrubberyCreationForm", 145, 137 )
{
   _target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(
    const ShrubberyCreationForm &other )
  : AForm::AForm( other.getName(), other.getRequiredGrade(),
                  other.getExecuteGrade() )
{
   _target = other._target;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=( const ShrubberyCreationForm &other )
{
   if ( this != &other )
   {
      AForm::operator=( other );
      _target = other._target;
   }

   return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
}

void ShrubberyCreationForm::execute( const Bureaucrat &executer ) const
{
   if ( !isSigned() )
      throw AForm::NotSignedException();
   if ( executer.getGrade() <= getExecuteGrade() )
   {
      std::fstream file;
      openFile( _target, file );
      DrawTree( file );
      file.close();
   }
   else
      throw Bureaucrat::GradeTooLowException();
}
