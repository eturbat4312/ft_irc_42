#include "../../includes/Buffer.hpp"

Buffer::Buffer() : _buf1(), _buf2(){
	std::cout << "Buffer object created " << std::endl;
	clearBufs();
}

Buffer::~Buffer(){}

char*	Buffer::getBuf(int id){
	if (!id)
		return (_buf1);
	else if (id == 2)
		return (_buf2);
	else
		join();
	return (_buf1);
}

void	Buffer::clearBuf(int id){
char *buf;
if (id == 1) {
    buf = _buf1;
} else {
    buf = _buf2;
}
for (int i = 0; i < BUF_SIZE; i++)
		buf[i] = '\0';
}

void	Buffer::clearBufs(){
	clearBuf(1);
	clearBuf(2);
}

void	Buffer::join(){
	int i = 0, j = 0;
	while (i < BUF_SIZE && _buf1[i])
		i++;
	while (i < BUF_SIZE && _buf2[j]){
		_buf1[i] = _buf2[j];
		i++;
		j++;
	}
	clearBuf(2);
}