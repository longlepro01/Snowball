// mock data for testing
export const handler = async () => {
  return {
    statusCode: 200,
    body: JSON.stringify({
      goals: [
        {
          id: "1",
          title: "Learn Art Fundamentals",
          description: "Build core drawing and observation skills.",
          // segments: [
          //   { title: "Drawing Landscapes", description: "Practice perspective", completed: false },
          //   { title: "Anatomy Basics", description: "Study human proportions", completed: false },
          //   { title: "Shading & Light", description: "Learn light and shadow", completed: false }
          // ]
        },
        {
          id: "2",
          title: "Learn Boxing",
          description: "I want to be fast on my feet to dodge blows and throw hard punches.",
        },
        {
          id: "3",
          title: "Learn C++",
          description: null,
        }
      ]
    })
  };
};
