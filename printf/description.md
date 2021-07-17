# ft_printf.c
ft_printf 라이브러리 프로토타입 함수가 있는 파일
ft_printf_print_manager.c의 `manage_print()`함수를 호출함.

* 가변 인자 포인터를 관리한다.
* 출력한 문자열의 길이를 반환한다.

# ft_printf_print_manager.c
인자로 받은 문자열을 돌면서 일반 문자는 출력하고, 서식 문자는
ft_printf_data_parser.c의 `parse_data()`함수를 호출함.

* 출력한 문자열의 길이를 반환한다.

# ft_printf_data_parser.c
인자로 받은 서식 문자열을 돌면서 정보를 파싱함. 파싱이 정상적으로 종료되면, 서식 문자열의 출력을 담당하는 ft_printf_data_printer.c의 `print_data()`함수를 호출함.

이 파일에서 잡아낼 수 있는 에러: 형식 문자가 정의되지 않은 문자인 경우

* 출력한 문자열의 길이를 반환한다.
* 서식 문자열에 오류가 있는 경우, ERROR를 반환한다.

# ft_printf_data_printer.c
인자로 받은 구조체의 타입을 기준으로 `handle_xxx_type()` 함수를 호출하여 출력한다.

# ft_printf_c_type.c


# ft_printf_utils.c

# ft_printf_syntax.c