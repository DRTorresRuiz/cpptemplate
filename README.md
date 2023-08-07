# C++ template


## Get git hooks working

By default, Git saves hooks in folder `.git/hooks`.
You can always place our hooks in the `.git/hooks` folder to work with them.
However, this folder is not tracked by Git itself since it is placed within the `.git` folder.

We want Git to track our hooks and include them in our template.
To do so, we have to set a new `core.hooksPath` for the `git` command:

```shell
  git config core.hooksPath .hooks/
```

We can also set this configuration globally including the `--global` option, and change the path of
the hooks, which in our example above is `.hooks/`.


## Troubleshooting

- **Hook was ignored because it's not set as executable**. If `git` ignores your hooks, give them additional permissions:
  
    ```shell
    chmod -R u+x .hooks/
    ```


---

*Daniel R. Torres Ruiz © 2023*