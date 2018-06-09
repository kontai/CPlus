#include "stdafx.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace TestProject1
{
	[TestClass]
	public ref class UnitTest
	{
	private:
		TestContext^ testContextInstance;

	public: 
		/// <summary>
		///取得或設定提供目前測試回合
		///相關資訊與功能的測試內容。
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

		#pragma region Additional test attributes
		//
		//您可以使用下列其他屬性撰寫測試: 
		//
		//執行該類別中第一項測試前，使用 ClassInitialize 執行程式碼
		//[ClassInitialize()]
		//static void MyClassInitialize(TestContext^ testContext) {};
		//
		//在類別中的所有測試執行後，使用 ClassCleanup 執行程式碼
		//[ClassCleanup()]
		//static void MyClassCleanup() {};
		//
		//在執行每一項測試之前，先使用 TestInitialize 執行程式碼
		//[TestInitialize()]
		//void MyTestInitialize() {};
		//
		//在執行每一項測試之後，使用 TestCleanup 執行程式碼
		//[TestCleanup()]
		//void MyTestCleanup() {};
		//
		#pragma endregion 

		[TestMethod]
		void TestMethod1()
		{
			//
			// TODO:  在此加入測試邏輯
			//
		};
	};
}
