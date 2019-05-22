#include "chessboard-interface.hh"
#include "chessboard.hh"
#include "listener.hh"
#include "pgn-move.hh"
#include "pgn-parser.hh"
#include "position.hh"
#include "report-type.hh"

#include "boost/program_options.hpp" 
 
#include <iostream> 
#include <string> 
#include <vector>

namespace 
{ 
  const size_t ERROR_IN_COMMAND_LINE = 1; 
  const size_t SUCCESS = 0; 
  const size_t ERROR_UNHANDLED_EXCEPTION = 2; 
 
} // namespace

 
int main(int argc, char* argv[])
{
try 
  { 
    /** Define and parse the program options 
     */ 
    namespace po = boost::program_options; 
    po::options_description desc("Options"); 
    desc.add_options() 
      ("help,h", "show usage") 
      ("pgn", po::value<std::string>(), "path to the PGN game file") 
      ("listeners,l", po::value< std::vector<std::string> >()->multitoken(), "list of paths to listener plugins") 
      ("perft", po::value<std::string>(), "path to a perft file"); 
 
    po::variables_map vm; 
    try 
    { 
      po::store(po::parse_command_line(argc, argv, desc),  
                vm); // can throw 
 
      /** --help option 
       */ 
      if ( vm.count("help")  ) 
      { 
        std::cout << "Basic Command Line Parameter App" << std::endl 
                  << desc << std::endl; 
        return SUCCESS; 
      } 

      if ( vm.count("pgn"))
      {
        std::cout <<"pgn file: "
                  << vm["pgn"].as<std::string>() << "\n";
      }
      if ( vm.count("listeners"))
      {
        std::cout <<"listeners plugins: ";
        for ( auto v :  vm["listeners"].as< std::vector<std::string>>() )
            std::cout << v << "\n";
      }
      if ( vm.count("perft"))
      {
        std::cout <<"perft file: "
                  << vm["perft"].as<std::string>() << "\n";
      }


      po::notify(vm); // throws on error, so do after help in case 
                      // there are any problems 
    } 
    catch(po::error& e) 
    { 
      std::cerr << "ERROR: " << e.what() << std::endl << std::endl; 
      std::cerr << desc << std::endl; 
      return ERROR_IN_COMMAND_LINE; 
    } 
 
    // application code here // 
 
  } 
  catch(std::exception& e) 
  { 
    std::cerr << "Unhandled Exception reached the top of main: " 
              << e.what() << ", application will now exit" << std::endl; 
    return ERROR_UNHANDLED_EXCEPTION; 
 
  } 


  Chessboard board{};
  std::cout << board.moveRockE(board.board_pieces[3]) << " move East\n";
  std::cout << board.moveRockS(board.board_pieces[3]) << " move South\n";
  std::cout << board.moveRockW(board.board_pieces[3]) << " move West\n";
  std::cout << board.moveRockN(board.board_pieces[3]) << " move North\n";

  std::cout << board.moveBishopNE(board.board_pieces[0]) << " move NorthEast\n";
  std::cout << board.moveBishopSE(board.board_pieces[1]) << " move SouthEast\n";
  std::cout << board.moveBishopNW(board.board_pieces[10]) << " move NW\n";
  std::cout << board.moveBishopSW(board.board_pieces[10]) << " move SW\n";
 
  return 0;
}
