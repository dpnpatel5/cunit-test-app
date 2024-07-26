# Example App With Cunit Framework

This project includes an application and a set of tests using the CUnit framework.

## CUnit Framework

This application is tested with the CUnit framework. The specific version used is: Tag: 3.2.7

```bash
git clone --branch 3.2.7 --single-branch https://gitlab.com/cunity/cunit.git open-source/cunit
```

## Building the Application

To compile the application binary, use the following command:

```bash
make
```

To compile the test application with CUnit enabled, use:

```bash
make CUNIT_ENABLE=1
```

