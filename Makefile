NAME		=	ircserv

SDIR		=	srcs

SRCS		=	main.cpp parsing.cpp\
				utils.cpp data_init.cpp \
				classes/Buffer.cpp classes/Client.cpp classes/User.cpp classes/Channel.cpp

IDIR		=	incs

ODIR		=	objs

OBJS		=	$(addprefix $(ODIR)/,$(SRCS:.cpp=.o))

RM			=	rm -rf

CXX			=	c++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

$(ODIR)/%.o	:	$(SDIR)/%.cpp $(INCS)
			@mkdir -p $(@D)
			$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME)		:	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all			:	$(NAME)

clean		:
			$(RM) $(ODIR)

fclean		:	clean
			$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
