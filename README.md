
Small CLI tool to manage Bible notes.

1. init
`./run init folder_name`

output: 
`BNC`
`└── Luke`

2. add
`./run add file_name folder_name

output:
`BNC`
`├── .commit`
`│   └── Luke`
`└── Luke`
  ``  └── chap1`

3. commit
`./run commit folder_name file_name commit`

output: 
`BNC
`├── .commit`
`│   └── Luke`
`│       └── chap1`
`└── Luke`
`    └── chap1`

4. log
`./run log folder_name file_name`

output:
`commit`