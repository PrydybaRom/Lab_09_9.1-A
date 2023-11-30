#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_09_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest91
{
    TEST_CLASS(UnitTest91)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            // Arrange
            Student student = { "Ivanov", 2, Spec::ME, 5, 4, 3 };

            // Act
            float result = calcArg(student);

            // Assert
            Assert::AreEqual(result, 4.0f, 0.001f);
        }
    };
}

