# Commit Message Convention (Udacity)

> 유다시티의 커밋 메시지 스타일 가이드 참조

## 1. Commit Message Structure

- 기본적으로 제목/본문/꼬리말 구성

```markdown
<type>: <subject>

<body>

<footer>
```



## 2. Commit Type

- `feat`: 새로운 기능 추가
- `fix`: 버그 수정
- `docs`: 문서 수정
- `style`: 코드 포맷팅, 세미콜론 누락, 코드 변경이 없는 경우
- `refactor`: 코드 리팩토링
- `test`: 테스트 코드, 리팩토링 테스트 코드 추가
- `chore`: 빌드 업무 수정, 패키지 매니저 수정 (생산성 코드 수정 X)



## 3. Subject

- 제목은 50자 미만으로 대문자로 작성하고 마침표는 붙이지 않음.
- 과거시제 X, 명령어로 작성
  - "Fixed" => "Fix"
  - "Added" => "Add" 



## 4. Body

- 선택사항이기 때문에 모든 커밋에 본문 내용 작성할 필요는 없음.
- 부연 설명 필요 시 또는 커밋의 이유를 설명할 경우
- 72자를 넘기지않고 제목과 구분되기 위해 한칸 띄워 작성함.



## 5. Footer

- 선택사항이라 모든 커밋에 꼬리말 작성할 필요 X
- `Issue tracker id`를 작성할 때 사용



## 6. Example

``` markdown
feat: Summarize changes in around 50 characters or less

More detailed explanatory text, if necessary. Wrap it to about 72
characters or so. In some contexts, the first line is treated as the
subject of the commit and the rest of the text as the body. The
blank line separating the summary from the body is critical (unless
you omit the body entirely); various tools like `log`, `shortlog`
and `rebase` can get confused if you run the two together.

Explain the problem that this commit is solving. Focus on why you
are making this change as opposed to how (the code explains that).
Are there side effects or other unintuitive consequenses of this
change? Here's the place to explain them.

Further paragraphs come after blank lines.

- Bullet points are okay, too

- Typically a hyphen or asterisk is used for the bullet, preceded
by a single space, with blank lines in between, but conventions
vary here

If you use an issue tracker, put references to them at the bottom,
like this:

Resolves: #123
See also: #456, #789
```

