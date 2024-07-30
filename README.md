# AntiDebugProtector

**AntiDebugProtector**는 디버거와 분석 도구를 감지하고 방어하는 기능을 갖춘 C++ 프로젝트입니다. 이 레포지토리는 여러 디버깅 도구의 실행을 모니터링하고, 발견된 도구에 대해 다양한 조치를 취하는 코드를 포함하고 있습니다.

## 주요 기능
- **프로세스 감지**: 특정 이름의 프로세스를 검색하여 그 존재 여부를 확인합니다.
- **블루 스크린 오류 발생**: 시스템을 강제로 블루 스크린 상태로 만들어 디버깅 도구를 방해합니다.
- **프로세스 종료**: 디버깅 도구와 분석 소프트웨어를 자동으로 종료시킵니다.
- **디버거 감지 및 대응**: 다양한 디버거와 분석 도구의 실행 여부를 주기적으로 확인하고 로그를 출력합니다.

## 코드 설명
- **헤더 파일 포함**: 필요한 라이브러리와 헤더 파일을 포함합니다.
- **프로세스 검색**: 특정 프로세스를 찾아 ID를 반환합니다.
- **블루 스크린 및 프로세스 종료**: 시스템 오류를 유도하거나 특정 프로세스를 종료합니다.
- **디버거 감지 및 대응**: 디버거와 관련된 프로세스 및 창을 감지하고 처리합니다.
- **멀티스레딩**: 여러 보호 기능을 동시에 실행하기 위해 스레드를 사용합니다.

이 레포지토리는 악성 코드 또는 디버깅 도구의 사용을 방지하려는 목적을 가지고 있으며, 주의하여 사용해야 합니다.

# **면책 조항(Disclaimer)**
### English
By using this code, the author bears no responsibility for any issues that may arise. The usage of this code is at the user's discretion, and any consequences resulting from it are solely the responsibility of the user. The author assumes no liability for any outcomes or damages incurred from the use of this code. The user absolves the author of any accountability for losses or damages resulting from the usage of this code. By using this code, the user agrees to the following terms and acknowledges being sufficiently warned of any potential risks associated with its use:

1. **Freedom of Use:** The usage of the code is at the user's discretion, and the author imposes no restrictions.
2. **Responsibility:** The user bears sole responsibility for any issues arising from the use of the code.
3. **Consequences of Usage:** The author disclaims all responsibility for any outcomes resulting from the use of the code.
4. **Liability Waiver:** The user holds the author harmless from any losses or damages resulting from the usage of the code.

### Korean
이 코드를 사용함으로써 발생하는 어떤 문제에도, 작성자는 일체의 책임을 지지 않습니다. 코드를 사용하는 것은 사용자의 자유이며, 이로 인해 발생하는 모든 문제에 대한 책임은 오로지 사용자에게 있습니다. 이 코드를 사용함으로써 발생하는 어떠한 결과에도 작성자는 일체의 책임을 지지 않으며, 이 코드를 사용함으로써 발생하는 어떠한 손실이나 손해에 대해 사용자는 작성자를 책임 지지 않습니다. 이 코드를 사용함으로써 사용자는 다음 사항에 동의하며, 이 코드를 사용함으로써 발생할 수 있는 모든 위험에 대해 충분히 경고받았음을 인지해야 합니다:

1. **자유로운 사용**: 코드를 사용하는 것은 사용자의 자유이며, 작성자는 사용 제약을 가하지 않습니다.
2. **책임의 귀속**: 코드 사용으로 발생하는 모든 문제에 대한 책임은 오로지 사용자에게 있습니다.
3. **코드 사용의 결과**: 작성자는 코드 사용으로 발생하는 모든 결과에 대해 일체의 책임을 지지 않습니다.
4. **손실 또는 손해에 대한 면책**: 사용자는 코드 사용으로 발생하는 어떠한 손실이나 손해에 대해 작성자를 책임 지지 않습니다.
