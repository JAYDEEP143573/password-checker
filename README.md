# Password Strength Checker

This is are my frist repo on github.

A small C command-line tool that scores a password's strength based on length
and character variety. Built as a first-year BCA project on the way toward
cybersecurity fundamentals.

## Features

- Checks for uppercase, lowercase, digits, and special characters
- Tiered length scoring (8+ chars = OK, 16+ chars = stronger)
- Flags truncated input if the password exceeds the buffer size
- Rates the result as Weak / Moderate / Strong

## Build

```bash
make
```

## Run

```bash
./password_checker
# or
make run
```

Example:

```
=== Password Strength Checker ===
Enter a password: MyP@ssw0rd123!

--- Analysis ---
Length: 14 characters (OK, 16+ is stronger)
Uppercase letter: Yes
Lowercase letter: Yes
Number: Yes
Special character: Yes

Strength: Strong
```

## Clean

```bash
make clean
```

## How scoring works

| Check              | Points |
| ------------------ | ------ |
| Length >= 8         | 1      |
| Length >= 16        | 2 (replaces the 1-point tier) |
| Has uppercase       | 1      |
| Has lowercase       | 1      |
| Has digit           | 1      |
| Has special char    | 1      |

Total score out of 6:
- 0–2 → Weak
- 3–4 → Moderate
- 5–6 → Strong

## Possible next steps

- Estimate crack time based on character set size and length
- Check against a list of common/leaked passwords
- Add a `--generate` flag to suggest a strong password

## License

MIT
