# zenohpico for Unikraft

This is the port of zenohpico for Unikraft as external library.

### Getting started

Add the library manifest to your kraft list

    kraft list add https://github.com/aaly/lib-zenohpico
    
Then update manifests list, but make sure to have set ***UK_KRAFT_GITHUB_TOKEN***

    kraft list update
    
Then pull the library

    kraft list pull -g https://github.com/aaly/lib-zenohpico

Finally, add zenohpico to your unikernel (wthin the directory) by 

    kraft lib add zenohpico

### Documentation
#### Zenoh Pico
Please refer to [`README.md`](https://github.com/eclipse-zenoh/zenoh-pico) of the Eclipse zenoh native C library repo.
#### Unikraft
Please refer to the [`README.md`](https://github.com/unikraft/unikraft/tree/staging/README.md)
as well as the documentation in the [`doc/`](https://github.com/unikraft/unikraft/tree/staging/doc/)
subdirectory of the main unikraft repository.
