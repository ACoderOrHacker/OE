# Contributing

## Issue reporting

- Check that the issue has not already been reported.
- Check that the issue has not already been fixed in the latest version.
- Be clear and concise in your issue description.
- Be friendly and respectful.
- Include any relevant code snippets or error messages.
- Open a new issue with grammatically correct, complete sentences.

## Pull requests

- No conflicting on the same branch.
- PRs must be good and well-written.
- Commits must be atomic and have clear, descriptive English messages.
- Committing on dev branch is allowed.

## Code style

- Use clear, descriptive variable names.
- Write clear, concise comments.
- Use DDOX style comments for documenting D code.
- Use doxygen style comments for documenting C/C++ code.
- Macros starts with `OE_`.
- Every C/C++ Interfaces must be written in `oe::<module>::impl`.
- `oe::<module>::details` is for internal use only.
- Every C/C++ functions must add `OE_API` macro to their declaration.
- Use utf-8 encoding
- Snake case naming for naming variables and functions.
- Classes's member variables should be prefixed with `m_`.
- Indentation should be 4 spaces.
- Use clang-format(C/C++) and dfmt(D) to format code.
- Use `types` library when using types like std::uint8_t
- Use `scripts/add_module.sh` to add a new module.
- Add a config in [metas/configs.json](metas/configs.json) when adding a new config for a module.
